class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        // target[i][j][dir] stores the final {row, col} if we ENTER cell (i, j) moving in `dir`.
        // dir == 0 means entering moving RIGHT.
        // dir == 1 means entering moving DOWN.
        vector<vector<vector<pair<int, int>>>> target(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1})));

        // 1. Precompute final landing cells (Iterate backwards to resolve chains in O(1))
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    // Empty cell: The robot stops here regardless of how it entered
                    target[i][j][0] = {i, j};
                    target[i][j][1] = {i, j};
                } else {
                    // Mirror cell:
                    // If entered moving RIGHT (0), it reflects DOWN (1) to (i+1, j)
                    if (i + 1 < m) {
                        target[i][j][0] = target[i + 1][j][1];
                    }
                    // If entered moving DOWN (1), it reflects RIGHT (0) to (i, j+1)
                    if (j + 1 < n) {
                        target[i][j][1] = target[i][j + 1][0];
                    }
                }
            }
        }

        // 2. Push DP
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If cell is unreachable or is a mirror (robot never rests on a mirror)
                if (dp[i][j] == 0 || grid[i][j] == 1) continue;

                // Push Right: Enter (i, j+1) moving RIGHT (0)
                if (j + 1 < n) {
                    auto [r, c] = target[i][j + 1][0];
                    if (r != -1) {
                        dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                    }
                }

                // Push Down: Enter (i+1, j) moving DOWN (1)
                if (i + 1 < m) {
                    auto [r, c] = target[i + 1][j][1];
                    if (r != -1) {
                        dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};