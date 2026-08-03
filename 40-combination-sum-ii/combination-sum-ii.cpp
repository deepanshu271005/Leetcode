class Solution {
public:

      void f(vector<int>& candidates, int target,  vector<vector<int>>& ans,
           int idx, vector<int>& temp, int currsum) {
        if (currsum == target) {
             ans.push_back(temp);
            return;
        }
        if (currsum > target || idx >= candidates.size())
            return;

        // explore the possibilty to add this number again ;
        temp.push_back(candidates[idx]);
        f(candidates, target, ans, idx+1, temp, currsum + candidates[idx]);
        temp.pop_back();
        for(int i=idx+1; i<candidates.size() && candidates[i]==candidates[i-1];i++){
            idx=i;
        } 
        
        f(candidates, target, ans, idx+1, temp, currsum );
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>temp;
        f(candidates, target, ans, 0,temp, 0);
        return ans;
    }
};