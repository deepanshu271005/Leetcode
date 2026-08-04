class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=nums[0];
        vector<int>ans;
       map<int,int>m;
      for(auto i:nums)m[i]++;
        while(cnt<=nums[nums.size()-1]){
            if(m.count(cnt)==0){
                ans.push_back(cnt);
            }
            cnt++;
        }
        return ans;
    }
};