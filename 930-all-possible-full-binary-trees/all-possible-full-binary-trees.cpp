class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> allPossibleFBT(int n) {

        if (n % 2 == 0)
            return {};

        if (n == 1)
            return {new TreeNode(0)};

        if (memo.count(n))
            return memo[n];

        vector<TreeNode*> res;

        for (int i = 1; i < n; i += 2) {
            int leftNodes = i;
            int rightNodes = n - 1 - i;

            vector<TreeNode*> leftTrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightTrees = allPossibleFBT(rightNodes);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return memo[n] = res;
    }
};