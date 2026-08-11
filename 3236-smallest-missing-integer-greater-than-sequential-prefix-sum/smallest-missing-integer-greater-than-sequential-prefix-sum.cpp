class Solution {
public:
    int missingInteger(vector<int>& nums) {
    vector<int>m(51,0);
    for(auto i:nums)m[i]++;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)sum+=nums[i];
            else break;
        }
        while(sum<51){
            if(m[sum]==0)return sum;
            sum++;
        }
        return sum;
    }
};