class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<bool> engaged(n + 1, false);
        vector<int> dp(n + 1, 0);
        
        dp[n] = 1;
        if (s[0] == '0') return 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && s[i + 1] == '0') {
                engaged[i] = true;
                if (s[i] == '1' || s[i] == '2') {
                    dp[i] = dp[i + 2];
                    continue;
                } else {
                    return 0;
                }
            } else if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            
            dp[i] += dp[i + 1];
            
            if (i + 1 < n && !engaged[i + 1]) {
                string temp = {s[i], s[i + 1]};
                if (temp < "27") {
                    dp[i] += dp[i + 2];
                }
            }
        }
        
        return dp[0];
    }
};