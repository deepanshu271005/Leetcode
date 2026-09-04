class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int maxi=nums[0];
         for(int i=0;i<nums.size();i++){
            int mini=nums[i];
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
            }
            if( maxi- mini<=k)return i;
            maxi=max(maxi,nums[i]);
         }
         return -1;

    }
};