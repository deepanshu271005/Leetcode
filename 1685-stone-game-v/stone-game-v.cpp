class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        for (int len = 2; len <= n; ++len) {

            for (int i = 0; i <= n - len; ++i) {

                int j = i + len - 1;

                for (int k = i; k < j; ++k) {

                    int left_sum = prefix[k + 1] - prefix[i];
                    int right_sum = prefix[j + 1] - prefix[k + 1];

                    if (left_sum < right_sum) {

                        dp[i][j] = max(dp[i][j], left_sum + dp[i][k]);
                    } else if (left_sum > right_sum) {

                        dp[i][j] = max(dp[i][j], right_sum + dp[k + 1][j]);
                    } else {

                        dp[i][j] = max({dp[i][j], left_sum + dp[i][k],
                                        right_sum + dp[k + 1][j]});
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};