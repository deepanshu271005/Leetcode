class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m));
        dp[0][0].push_back(grid[0][0]);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Sort and remove duplicates to keep the state space minimal
                if (dp[i][j].size() > 1) {
                    sort(dp[i][j].begin(), dp[i][j].end());
                    dp[i][j].erase(unique(dp[i][j].begin(), dp[i][j].end()), dp[i][j].end());
                }
                
                for (int val : dp[i][j]) {
                    // Move down
                    if (i + 1 < n) {
                        dp[i + 1][j].push_back(val ^ grid[i + 1][j]);
                    }
                    // Move right
                    if (j + 1 < m) {
                        dp[i][j + 1].push_back(val ^ grid[i][j + 1]);
                    }
                }
            }
        }
        
        // Find the minimum XOR sum at the destination cell
        int min_xor = INT_MAX;
        for (int val : dp[n - 1][m - 1]) {
            min_xor = min(min_xor, val);
        }
        
        return min_xor;
    }
};