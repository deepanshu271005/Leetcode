class Solution {
public:
    void f(vector<int>& candidates, int target, set<vector<int>>& s,
           int idx, vector<int>& temp, int currsum) {
        if (currsum == target) {
            s.insert(temp);
        }
        if (currsum > target || idx >= candidates.size())
            return;

        // explore the possibilty to add this number again ;
        temp.push_back(candidates[idx]);
        f(candidates, target, s, idx, temp, currsum + candidates[idx]);
        temp.pop_back();
        f(candidates, target, s, idx+1, temp, currsum );
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
        f(candidates, target, s, 0,temp, 0);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};