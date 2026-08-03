class Solution {
public:
    void f(vector<int>& candidates, int target, vector<vector<int>>& ans,
           int idx, vector<int>& temp, int currsum,int k) {
        if (temp.size()==k && currsum == target) {
            ans.push_back(temp);
            return;
        }
        if (currsum > target || idx >= candidates.size() || temp.size()>k)
            return;

        // explore the possibilty to add this number again ;
        temp.push_back(candidates[idx]);
        f(candidates, target, ans, idx+1, temp, currsum + candidates[idx],k);
        temp.pop_back();
        f(candidates, target, ans, idx + 1, temp, currsum,k);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int>temp;
        f(a, n, ans, 0,temp, 0,k);
        
        return ans;
    }
};