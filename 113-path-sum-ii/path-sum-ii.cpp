/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* root, int t, vector<int>& path, vector<vector<int>>& ans,
           int curr) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        curr += root->val;
        if (root->left == NULL && root->right == NULL && curr == t) {
            ans.push_back(path);
        }

        f(root->left, t, path, ans, curr);
        f(root->right, t, path, ans, curr);
        path.pop_back();

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        f(root, targetSum, path, ans, 0);
        return ans;
    }
};