#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[60][40];

    void precompute() {
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 40; j++) {
                dp[i][j] = 1e9;
            }
        }
        
        dp[0][0] = 0;

        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 40; j++) {
                if (i == 0 && j == 0) continue;
                
                int res = 1e9;
                res = min(res, 1 + dp[max(0, i - 1)][j]);             
                res = min(res, 1 + dp[i][max(0, j - 1)]);             
                res = min(res, 1 + dp[max(0, i - 2)][j]);             
                res = min(res, 1 + dp[max(0, i - 1)][max(0, j - 1)]); 
                res = min(res, 1 + dp[max(0, i - 3)][j]);             
                res = min(res, 1 + dp[i][max(0, j - 2)]);             
                
                dp[i][j] = res;
            }
        }
    }

    string build_suffix(int r2, int r3, int r5, int r7, int rem_len) {
        string suf = "";
        for (int i = 0; i < rem_len; i++) {
            for (int d = 1; d <= 9; d++) {
                int d2 = 0, d3 = 0, d5 = 0, d7 = 0;
                if (d == 2) d2 = 1;
                else if (d == 3) d3 = 1;
                else if (d == 4) d2 = 2;
                else if (d == 5) d5 = 1;
                else if (d == 6) { d2 = 1; d3 = 1; }
                else if (d == 7) d7 = 1;
                else if (d == 8) d2 = 3;
                else if (d == 9) d3 = 2;
                
                int nr2 = max(0, r2 - d2);
                int nr3 = max(0, r3 - d3);
                int nr5 = max(0, r5 - d5);
                int nr7 = max(0, r7 - d7);
                
                int req_len = nr5 + nr7 + dp[nr2][nr3];
                int spaces_left = rem_len - 1 - i;
                
                if (req_len <= spaces_left) {
                    suf += to_string(d);
                    r2 = nr2; 
                    r3 = nr3; 
                    r5 = nr5; 
                    r7 = nr7;
                    break; 
                }
            }
        }
        return suf;
    }

    string smallestNumber(string num, long long t) {
        long long temp = t;
        int target_2 = 0, target_3 = 0, target_5 = 0, target_7 = 0;
        
        while (temp % 2 == 0) { target_2++; temp /= 2; }
        while (temp % 3 == 0) { target_3++; temp /= 3; }
        while (temp % 5 == 0) { target_5++; temp /= 5; }
        while (temp % 7 == 0) { target_7++; temp /= 7; }
        
        if (temp > 1) return "-1";

        precompute();

        int n = num.length();
        bool has_zero = false;
        int first_zero = n;
        
        // Prefix arrays for O(1) lookups
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            pref2[i+1] = pref2[i];
            pref3[i+1] = pref3[i];
            pref5[i+1] = pref5[i];
            pref7[i+1] = pref7[i];
            
            if (num[i] == '0') {
                has_zero = true;
                first_zero = i;
                break;
            }
            
            int d = num[i] - '0';
            if (d == 2) pref2[i+1]++;
            else if (d == 3) pref3[i+1]++;
            else if (d == 4) pref2[i+1] += 2;
            else if (d == 5) pref5[i+1]++;
            else if (d == 6) { pref2[i+1]++; pref3[i+1]++; }
            else if (d == 7) pref7[i+1]++;
            else if (d == 8) pref2[i+1] += 3;
            else if (d == 9) pref3[i+1] += 2;
        }

        if (!has_zero && pref2[n] >= target_2 && pref3[n] >= target_3 && 
            pref5[n] >= target_5 && pref7[n] >= target_7) {
            return num;
        }

        string ans;

        for (int i = min(n - 1, first_zero); i >= 0; i--) {
            int curr_p2 = pref2[i];
            int curr_p3 = pref3[i];
            int curr_p5 = pref5[i];
            int curr_p7 = pref7[i];

            int start_d = num[i] - '0' + 1;

            for (int d = start_d; d <= 9; d++) {
                int d2 = 0, d3 = 0, d5 = 0, d7 = 0;
                if (d == 2) d2 = 1;
                else if (d == 3) d3 = 1;
                else if (d == 4) d2 = 2;
                else if (d == 5) d5 = 1;
                else if (d == 6) { d2 = 1; d3 = 1; }
                else if (d == 7) d7 = 1;
                else if (d == 8) d2 = 3;
                else if (d == 9) d3 = 2;

                int need2 = max(0, target_2 - (curr_p2 + d2));
                int need3 = max(0, target_3 - (curr_p3 + d3));
                int need5 = max(0, target_5 - (curr_p5 + d5));
                int need7 = max(0, target_7 - (curr_p7 + d7));

                int req_len = need5 + need7 + dp[need2][need3];
                int rem_len = n - 1 - i;

                if (req_len <= rem_len) {
                    ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += build_suffix(need2, need3, need5, need7, rem_len);
                    return ans;
                }
            }
        }

        int total_req_len = target_5 + target_7 + dp[target_2][target_3];
        int new_len = max(n + 1, total_req_len);
        return build_suffix(target_2, target_3, target_5, target_7, new_len);
    }
};