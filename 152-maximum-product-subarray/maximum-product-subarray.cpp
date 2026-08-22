class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //i will forecefully end the max proecut at i
        // like the subarray to exist there must be a end point so i will make each 'i' a end point 
        //dp[i]=max product we can get if the subarray end at i
        // but for this to work i need to dp 
        //dp1[i]->max positive product we can get 
        //dp2[i]->max negative product we could get 
        //dp1[i]=max({dp1[i-1]*num,num,dp2[i-1]*num});
        //dp2[i]=min({dp1[i-1]*num,num,dp2[i-1]*num});
        int n=nums.size();
         vector<int>dp1(n);
         vector<int>dp2(n);
         dp1[0]=dp2[0]=nums[0];
         for(int i=1;i<n;i++){
           dp1[i]=max({nums[i],dp1[i-1]*nums[i],dp2[i-1]*nums[i]});
           dp2[i]=min({nums[i],dp1[i-1]*nums[i],dp2[i-1]*nums[i]});
         }


          int ans=INT_MIN;
          for(int i=0;i<n;i++){
             ans=max(dp1[i],ans);
          }
          return ans;


    }
};