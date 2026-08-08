class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<bool> engaged(
            n + 1,
            false); // if i am at ith index and i+1 is 0 then i is engaged so
                    // while calc dp state i will take care of this
        vector<int> dp(
            n + 1,
            0); // dp[i]->tell the number of ways to decore from i to last
        dp[n] = 1;
        if (s[0] == '0')
            return 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n && s[i + 1] == '0') {
                engaged[i] = 1;
                if (s[i] == '1' || s[i] == '2')
                    {dp[i] = dp[i + 2];continue;}
                else
                    return 0;
            }
           else if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            dp[i] += dp[i + 1]; // couting this character as individual charater
            if (i + 1 < n && !engaged[i + 1]) {
                string temp = {s[i], s[i + 1]};
                if (temp < "27")
                    dp[i] += dp[i + 2];
            }
        }
        for (auto i : dp)
            cout << i << " ";
        return dp[0];
    }
};