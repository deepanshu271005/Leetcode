class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                   dp[i][j]=nums[i];
                }
            }
        }

        vector<int>prefix(n);
      prefix[0]=nums[0];
      for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];;
      }
        //base case is set 
         for(int diff=1;diff<n;diff++){
            for(int i=0;i<n-1;i++){
               for(int j=1;j<n;j++){
                if(i>j)continue;
                if(j-i!=diff)continue;
               // if(dp[i][j]==0)continue;
                int tSum=prefix[j]-prefix[i]+nums[i];
                int ans1=tSum-dp[i+1][j];
                int ans2=tSum-dp[i][j-1];
                dp[i][j]=max(ans1,ans2);
               }
            }
         } 
         cout<<dp[0][n-1]<<endl;
         cout<<prefix[n-1]<<endl;
         if(prefix[n-1]-dp[0][n-1]<=dp[0][n-1])return true;
    
      return  false;

    }
};