class Solution {
public:
    void f(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int> temp) {
        
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        
        f(nums, idx + 1, ans, temp);
        
         
        temp.push_back(nums[idx]);
        f(nums, idx + 1, ans, temp);
        
        
       // temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        
        f(nums, 0, ans, temp);
        
        return ans;
    }
};