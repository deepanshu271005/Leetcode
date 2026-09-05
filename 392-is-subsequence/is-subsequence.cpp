class Solution {
public:
    bool isSubsequence(string s, string t) {
        // dp[i][j]->tell if it is possible to make a subsequence from string 1
        // upto index i and string 2 upto j

        int n = s.size();
        int m = t.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case
        for (int j = 0; j <= m; j++) {
            dp[0][j] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] =
                        dp[i][j]; // if both the character matches it simple jst
                                  // check weather the string before it also
                                  // mathces or not
                } else
                    dp[i + 1][j + 1] =
                        dp[i + 1][j]; // else ignore the current chacter in the
                                      // 2nd string and check if is could
                                      // already be made or not
            }
        }

        return dp[n][m];
    }
};