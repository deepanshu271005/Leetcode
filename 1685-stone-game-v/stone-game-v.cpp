class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        int dp[n][n];

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=(n-i); j++)
            {
                dp[j][i+j-1] = 0;
                if(i != 1)
                {
                    int sum = 0, sum2 = 0;
                    for(int k=j; k<(j+i); k++) sum += a[k];
                    for(int k=j; k<(j+i-1); k++)
                    {
                        sum2 += a[k];
                        sum -= a[k];
                        if(sum2 > sum) dp[j][j+i-1] = max(dp[j][j+i-1], sum + dp[k+1][j+i-1]);
                        else if(sum2 < sum) dp[j][j+i-1] = max(dp[j][j+i-1], sum2 + dp[j][k]);
                        else
                        {
                             dp[j][j+i-1] = max(dp[j][j+i-1], sum + dp[j][k]);
                             dp[j][j+i-1] = max(dp[j][j+i-1], sum + dp[k+1][j+i-1]);
                        }
                    }
                }
            }
        }

        return dp[0][n-1];

    }
};