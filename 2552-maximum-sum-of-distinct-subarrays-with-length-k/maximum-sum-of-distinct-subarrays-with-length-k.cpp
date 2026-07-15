class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        long long ans=0;
        int l=0,r=0;
         
        long long  curr_sum=0;
        while(r<nums.size()){
             
             while(m[nums[r]]!=0 || r-l+1>k){
                curr_sum-=nums[l];
                m[nums[l]]--;
                l++;
            }
            m[nums[r]]++;
            curr_sum+=nums[r];
            if(r-l+1==k){
                 
                ans=max(ans,curr_sum);
            }
            r++;
        }
        
        return ans;
    }
};