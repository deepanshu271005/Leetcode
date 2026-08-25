class Solution {
public:
    int numSquares(int n) {
        vector<int>square;
        int num=1;
        while(num*num<=n){
            square.push_back(num*num);
            num++;
        }
 
      vector<int>dp(n+1,INT_MAX);
      dp[1]=1;
      dp[0]=0;
      for(int i=2;i<=n;i++){
        for(int j=0;j<square.size() && square[j]<=i;j++){
            dp[i]=min(dp[i],1+dp[i-square[j]]);
        }
      }
    //    for(auto i:square)cout<<i<<" ";
    //    cout<<endl;
    //   for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<dp[i]<<endl;
    //   }

      return dp[n]; 
     
    }
};