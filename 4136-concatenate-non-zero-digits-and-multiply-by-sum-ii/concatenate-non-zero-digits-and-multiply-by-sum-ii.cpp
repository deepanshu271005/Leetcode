class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = s.size();

         vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> index;
        
         vector<long long> pref_val = {0}; 
        vector<long long> pref_sum = {0};

        long long current_val = 0;
        long long current_sum = 0;

         for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                index.push_back(i);
                int digit = s[i] - '0';
                
                 current_sum = current_sum + digit;
                pref_sum.push_back(current_sum);

                 current_val = (current_val * 10 + digit) % MOD;
                pref_val.push_back(current_val);
            }
        }

        vector<int> answer;
        
         for (auto& q : queries) {
            int l = q[0], r = q[1];
            
             auto it_start = lower_bound(index.begin(), index.end(), l);
            auto it_end = upper_bound(index.begin(), index.end(), r);
            
             if (it_start >= it_end) {
                answer.push_back(0);
                continue;
            }

             int L = it_start - index.begin();
            int R = it_end - index.begin() - 1;
            
             long long sum = pref_sum[R + 1] - pref_sum[L];
            
             int len = R - L + 1;
            long long x = (pref_val[R + 1] - (pref_val[L] * pow10[len]) % MOD + MOD) % MOD;
            
             long long res = (x * sum) % MOD;
            answer.push_back(res);
        }
        
        return answer;
    }
};