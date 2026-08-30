class Solution {
public:
    int getMoneyAmount(int n) {
        
     //dp[i][j]-> tell me the min cost i need 

     vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX/2));
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dp[i][j]=0;
        }
     } 

     //base case is set 

      for(int len=1;len<=n-1;len++){
        for(int i=1;i<=n;i++){
            int j=len+i;
            if(j>n)break;
            for(int k=i;k<=j;k++){
                //if i guess at k 

                dp[i][j]=min(dp[i][j],max((k==i)?0:dp[i][k-1]+k,(k==j)?0:dp[k+1][j]+k));
            }
        }
      }
        
        return dp[1][n];

    }
};