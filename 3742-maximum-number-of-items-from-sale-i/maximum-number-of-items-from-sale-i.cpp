class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        map<int, int> m;
        int n = items.size();
        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (items[j][0] % items[i][0] == 0) ans++;
            }
            m[i] = ans;
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int first_gain = 1 + m[i];

            if (price > budget) continue;

            for (int c = budget; c >= price; c--) {
                dp[c] = max(dp[c], dp[c - price] + first_gain);
            }

            for (int c = price; c <= budget; c++) {
                dp[c] = max(dp[c], dp[c - price] + 1);
            }
        }

        int best = 0;
        for (int c = 0; c <= budget; c++) {
            best = max(best, dp[c]);
        }
        return best;
    }
};