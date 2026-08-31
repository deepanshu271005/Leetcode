class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
      for(int i=0;i<nums.size();i++){
         int left=target-nums[i];
         auto it=lower_bound(nums.begin(),nums.end(),left);
         if(it==nums.end())continue;
         else {
            int idx=it-nums.begin();
            if(idx!=i && nums[i]+nums[idx]==target)return {min(idx+1,i+1),max(idx+1,i+1)};
         }
      }
      return {};

    }
};