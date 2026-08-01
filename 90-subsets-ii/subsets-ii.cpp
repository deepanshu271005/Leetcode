class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int>>ans;

         int n=nums.size();
         int total=1<<n;
        
        //now there are 0 to 2 powN -1 number whcih each represnet all the subset possible 
        for(int mask=0;mask<total;mask++){
            vector<int>temp;
            for(int i=0;i<11;i++){
                //check is the ith bit is on or not 
                if(1<<i & mask){
                 temp.push_back(nums[i]);
                }
                
            }
            sort(temp.begin(),temp.end());
            ans.insert(temp);
        }
        vector<vector<int>>a;
       for(auto i:ans){
        a.push_back(i);
       }
        return a;
    }
};