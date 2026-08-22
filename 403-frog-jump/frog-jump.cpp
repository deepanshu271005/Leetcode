class Solution {
public:
    bool canCross(vector<int>& stones) {
        //dp[i][k]-> is this possible to reach the stones[i] with k steps
        //dp[i][k]=for(all)dp[i][j]=dp[i-1][stone[i]-stone[i-1]];and check for k-1 and k+1
      
          int n=stones.size();
        //   vector<vector<bool>>dp(n,vector<bool>(2000,false));
        //   dp[0][0]=true;
        //   for(int i=1;i<n;i++){
        
        //      int k=stones[i]-stones[i-1];
                    
        //          for(int j=i-1;j>=0;j--){
        //             cout<<"aua ";
        //            dp[i][k]=dp[i][k] || dp[j][k];
        //            dp[i][k]=dp[i][k] || dp[j][k-1];
        //            dp[i][k]=dp[i][k] || dp[j][k+1];
        //            if(dp[i][k])break;
        //              }
        //   }
        //      for(int i=0;i<2000;i++){
        //            if(dp[n-1][i])return true;
        //      }
        //      return false;

         vector<vector<int>>dp(n,vector<int>());
         //dp[i]->able to reach stone [i] with steps = dp[i]=k;

         dp[0].push_back(0);
         for(int i=1;i<n;i++){
           for(int j=i-1;j>=0 ;j--){
            int k=stones[i]-stones[j];
            auto it=lower_bound(dp[i].begin(),dp[i].end(),k);
            if(it!=dp[i].end() && dp[i][it-dp[i].begin()]==k){
                 continue;
            }
            for(auto k1:dp[j]){
                if(k1==k || k1==k-1 || ((k==INT_MAX)?false:k1==k+1)){
                    dp[i].push_back(k);
                    break;
                }
             }
             }
            }

        //  for(int i=0;i<n;i++){
        //     cout<<"stone:"<<i;
        //     cout<<"  stpes:"<<dp[i]<<endl;
        //  }

         if(dp[n-1].size()==0)return false;
         return true;

    }
};