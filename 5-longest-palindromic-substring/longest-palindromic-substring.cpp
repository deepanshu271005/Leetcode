class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // for(int i=0;i<n;i++)dp[i][i]=1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i > j)
                    continue;
                if (i == j)
                    dp[i][j] = 1;
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }
        int ans = 0;
        int x = 0; // Start index

        // Find the maximum length in the populated table
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (dp[i][j] == true) {
                    if (j - i + 1 > ans) {
                        ans = j - i + 1;
                        x = i;
                    }
                }
            }
        }

        return s.substr(x, ans);
    }
};