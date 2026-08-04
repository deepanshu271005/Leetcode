class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=nums[0];
        vector<int>ans;
        int idx=0;
       //vector<int>freq(101,0);
    //  for(auto i:nums)freq[i]++;
        while(cnt<=nums[nums.size()-1]){
           if(nums[idx]!=cnt){
            ans.push_back(cnt);
            cnt++;
           }
           else {
            cnt++;idx++;
           }
            
        }
        return ans;
    }
};