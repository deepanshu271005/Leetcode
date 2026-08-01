class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //as the value of n is simply 10 we can use bit masking to create all the subset 
        int n=nums.size();
        int total=1<<n;
        vector<vector<int>>ans;
        //now there are 0 to 2 powN -1 number whcih each represnet all the subset possible 
        for(int mask=0;mask<total;mask++){
            vector<int>temp;
            for(int i=0;i<11;i++){
                //check is the ith bit is on or not 
                if(1<<i & mask){
                 temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};