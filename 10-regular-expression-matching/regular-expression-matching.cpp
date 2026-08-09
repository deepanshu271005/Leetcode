class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (p[j - 1] == '*') {
                    // 1. Zero occurrences: ignore the '*' and the preceding
                    // character
                    dp[i][j] = dp[i][j - 2];

                    // 2. One or more occurrences: only valid if the preceding
                    // pattern char matches current string char
                    if (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } 
                else {
                    if (i>0 && j>0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1]) &&
                        dp[i - 1][j - 1])
                        dp[i][j] = true;
                }
            }
        }
        return dp[n1][n2];
    }
};