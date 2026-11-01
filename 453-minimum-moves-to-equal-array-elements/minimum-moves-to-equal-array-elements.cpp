class Solution {
public:
    int minMoves(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        //in one operation we can dec any one element that is simply equilavelent to inc all other by 1 
        int ans=0;
        int mini=nums[0];
        for(auto i:nums){
            ans+=(i-mini);
        }
        return ans;

    }
};