class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=k;true;i+=k){
            auto it=lower_bound(nums.begin(),nums.end(),i);
            if(it!=nums.end() && *it==i)continue;
            return i;
        }
        return 0;
    }
};