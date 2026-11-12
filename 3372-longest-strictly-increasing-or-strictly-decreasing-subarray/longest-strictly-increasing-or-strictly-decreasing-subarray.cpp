class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>inc(n,1);
        vector<int>dec(n,1);
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc[i]=max(1,inc[i-1]+1);
            }
            else if(nums[i]<nums[i-1]){
                dec[i]=max(1,dec[i-1]+1);
            }
           
        }
        int ans=1;
        for(auto i:inc){
            ans=max(ans,i);
        }
        for(auto i:dec){
            ans=max(ans,i);
        }
        return ans;
    }
};