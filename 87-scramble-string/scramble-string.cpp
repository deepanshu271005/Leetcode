class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(
            n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        // dp[len][i][j]->is the string of length 'len' in s1 starting from ith
        // index is scrambeled of string of len starting from j in s2

        // base case
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= n; len++) {

            for (int i = 0; i <= n - len; i++) {

                for (int j = 0; j <= n - len; j++) {

                    // now for this i need to check for every breaking point if
                    // there is one dp that state true for breaking from that
                    // point

                    for (int k = 1; k < len; k++) {
                        // Condition 1: No swap
                        bool noSwap = dp[k][i][j] && dp[len - k][i + k][j + k];

                        // Condition 2: Swap
                        bool swap =
                            dp[k][i][j + len - k] && dp[len - k][i + k][j];

                        if (noSwap || swap) {
                            dp[len][i][j] = true;
                            break; 
                        }
                    }
                }
            }
        }

        return dp[n][0][0];
    }
};