class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(abs(target-(nums[i]+nums[j]+nums[k]))<abs(ans-target)){
                        ans=nums[i]+nums[j]+nums[k];
                    }
                }
            }
        }
        return ans;
    }
};