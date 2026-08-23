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
    void f(vector<int>& nums, vector<vector<int>>& permutation,
           vector<int>& curr, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            permutation.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                curr.push_back(nums[i]);
                visited[i] = true;
                f(nums, permutation, curr, visited);
                curr.pop_back();
                visited[i] = 0;
                // f(nums, permutation, curr,visited);
            }
        }

        return;
    }

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* root, int val) {
        // Base case: found the empty spot to insert the new node
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Recursive step: go left if smaller, go right if larger
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else if (val > root->val) {
            root->right = insert(root->right, val);
        }

        return root;
    }

    // Function to build a full BST from one permutation array
    TreeNode* buildTree(const vector<int>& perm) {
        if (perm.empty())
            return nullptr;

        TreeNode* root = nullptr;
        for (int val : perm) {
            root = insert(root, val);
        }

        return root;
    }
    string serialize(TreeNode* root) {
        if (!root)
            return "null,";
        return to_string(root->val) + "," + serialize(root->left) +
               serialize(root->right);
    }

    vector<TreeNode*> generateTrees(int n) {
        // the simple way of doing this is simply generate all the permutation
        // of array [1 to n] and feed it to  the BST creater fucntion and store
        // the ans in set
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        vector<vector<int>> permutation;
        vector<bool> visited(n, false);
        vector<int> curr;
        f(nums, permutation, curr, visited);

        unordered_set<string> seenShapes;
        vector<TreeNode*> uniqueTrees;

        for (const auto& p : permutation) {
            TreeNode* temp = buildTree(p);
            string shape = serialize(temp);

            // If this shape string isn't in our set yet, it's a new unique tree
            if (seenShapes.find(shape) == seenShapes.end()) {
                seenShapes.insert(shape);
                uniqueTrees.push_back(temp);
            }
        }
        return uniqueTrees;
    }
};