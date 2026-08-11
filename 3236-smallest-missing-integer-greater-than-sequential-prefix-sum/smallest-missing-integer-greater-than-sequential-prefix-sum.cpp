class Solution {
public:
    int missingInteger(vector<int>& nums) {
    map<int,int>m;
    for(auto i:nums)m[i]++;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)sum+=nums[i];
            else break;
        }
        while(true){
            if(m.find(sum)==m.end())return sum;
            sum++;
        }
        return sum;
    }
};