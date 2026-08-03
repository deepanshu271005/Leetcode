class Solution {
public:
    void f(vector<int>& candidates, int target, vector<vector<int>>& ans,
           int idx, vector<int>& temp, int currsum) {
        if (currsum == target) {
            ans.push_back(temp);
            return;
        }
        if (currsum > target || idx >= candidates.size())
            return;

        // explore the possibilty to add this number again ;
        temp.push_back(candidates[idx]);
        f(candidates, target, ans, idx, temp, currsum + candidates[idx]);
        temp.pop_back();
        f(candidates, target, ans, idx+1, temp, currsum );
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // i will create all the valid comination as the value of n is very
        // small and also if the question only asked about the cnt then i could
        // have easily used dp for finding the cnt for this i need to exact
        // trackback
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int>temp;
        f(candidates, target, ans, 0,temp, 0);
        
        return ans;
    }
};