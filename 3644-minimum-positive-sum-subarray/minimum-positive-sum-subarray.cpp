class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                if(j-i+1<l || j-i+1>r)continue;
                 for(int k=i;k<=j;k++){
                    sum+=nums[k];
                 }   
                 if(sum>0)ans=min(sum,ans);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};