class Solution {
public:
    int integerBreak(int n) {
      
      if(n==2)return 1;
      if(n==3)return 2;

      vector<int>dp(n+1);
      dp[2]=1;
      dp[3]=2;
      for(int i=4;i<=n;i++){
        int spf = (dp[i-1] == 2) ? 1 : ((dp[i-1] % 2 == 0) ? 2 : 3);
        dp[i]=dp[i-1]+(dp[i-1]/spf);
      }
    // for(int i=2;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
     return dp[n];

    }
};