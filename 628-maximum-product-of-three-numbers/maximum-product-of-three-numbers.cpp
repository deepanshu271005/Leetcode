class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //ans will be max(first 2 -ve and first positive,first three postive);
        int ans1=1;
        int cnt=0;
         int ans=max(nums[0]*nums[1]*nums[nums.size()-1],nums[nums.size()-1]*nums[nums.size()-3]*nums[nums.size()-2]);
         return ans;

    }
};