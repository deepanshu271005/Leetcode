class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& visited, vector<int>& temp) {
        // Base case: if we have a full permutation, add it to our answers
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
     
        for(int i = 0; i < nums.size(); i++) {
             
            if(!visited[i]){
                
                visited[i] = 1;
                temp.push_back(nums[i]);
                
                
                f(nums, ans, visited, temp); 
                
              
                visited[i] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> visited(nums.size(), 0);
        vector<int> temp;
        
        f(nums, ans, visited, temp);
        
        return ans;
    }
};