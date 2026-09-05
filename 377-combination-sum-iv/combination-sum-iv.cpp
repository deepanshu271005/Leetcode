class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<unsigned int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
           auto it=upper_bound(nums.begin(),nums.end(),i);
           int idx=it-1-nums.begin();
           while(idx>-1){
            int left=i-nums[idx];
            dp[i]+=dp[left];
            idx--;
           } 
        }
        return dp[target];
    }
};