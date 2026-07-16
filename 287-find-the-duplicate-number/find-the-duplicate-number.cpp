class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //easiest is if i sort this and then compare all the adjacent element 
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])return nums[i];
        }
        return -1;
    }
};