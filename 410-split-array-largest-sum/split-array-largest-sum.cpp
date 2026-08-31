class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));

        //dp[i][k]->what is the minimised largest sum that i can get from 0 to i array if i split the array into k parts 
       
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        //prefix is one based index because my dp is also one based indexing 
        //base case if k=1;

        for(int i=1;i<=n;i++){
            dp[i][1]=prefix[i];
        }

        //if  a state dp[i][k] is INT_MAX this means its impossible state that means that we cant cut k parts from it 

        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                if(j>i)break;
                for(int cut=1;cut<=i;cut++){
                    dp[i][j]= min(dp[i][j],max(dp[cut][j-1],prefix[i]-prefix[cut]));
                }
            }
        }

       return dp[n][k];
    }
};