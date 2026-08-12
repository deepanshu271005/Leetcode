class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //not dp 
        int l=0;int r=0;int ans=INT_MIN;
        unordered_map<int,int>m;
        int n=nums.size();
        while( r<n){
              m[nums[r]]++;
              while(m[nums[r]]>k){
               // cout<<"aya";
                m[nums[l]]--;
                l++;
              }
              int window_size=r-l+1;
              r++;
              ans=max(ans,window_size);
        }

            return ans;
    }
};