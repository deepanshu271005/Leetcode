class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median=(n/2);
        int ans=0;
        for(auto i:nums){
            ans+=abs(nums[median]-i);
        }
        return ans;
    }
};