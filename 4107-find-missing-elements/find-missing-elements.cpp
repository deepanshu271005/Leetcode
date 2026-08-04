class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=nums[0];
        vector<int>ans;
       vector<int>freq(101,0);
      for(auto i:nums)freq[i]++;
        while(cnt<=nums[nums.size()-1]){
            if(freq[cnt]==0){
                ans.push_back(cnt);
            }
            cnt++;
        }
        return ans;
    }
};