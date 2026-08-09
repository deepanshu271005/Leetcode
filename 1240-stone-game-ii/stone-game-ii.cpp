class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
     
        vector<int> suffix(n, 0);
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
      
                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                } else {
                
                    for (int x = 1; x <= 2 * m; x++) {
                        int next_m = max(m, x);
                        dp[i][m] = max(dp[i][m], suffix[i] - dp[i + x][next_m]);
                    }
                }
            }
        }
        
        return dp[0][1];
    }
};