class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>backmin(nums.size());
        backmin.back()=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            backmin[i]=min(nums[i],backmin[i+1]);
        }
        int maxi=nums[0];
     // for(auto i:backmin)cout<<i<<" ";
        for(int i=0;i<nums.size();i++){
             maxi=max(maxi,nums[i]);
            if(maxi-backmin[i]<=k)return i;
           
        }
        return -1;
    }
};