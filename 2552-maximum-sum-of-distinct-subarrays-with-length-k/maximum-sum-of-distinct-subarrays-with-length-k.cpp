class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        long long ans=0;
        int l=0,r=0;
        vector<long long>prefix;
        long long  curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            prefix.push_back(curr_sum);
        }
        while(r<nums.size()){
             
             while(m[nums[r]]!=0 || r-l+1>k){
                m[nums[l]]--;
                l++;
            }
            m[nums[r]]++;
            if(r-l+1==k){
                long long left_sum = (l > 0) ? prefix[l - 1] : 0;
                ans=max(ans,prefix[r]-left_sum);
            }
            r++;
        }
        
        return ans;
    }
};