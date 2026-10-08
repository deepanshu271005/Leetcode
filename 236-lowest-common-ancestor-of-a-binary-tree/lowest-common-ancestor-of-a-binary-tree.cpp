/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getsize(TreeNode* root) {
    if (root == NULL)
        return 0;
    int size = 1;
    size += getsize(root->left);
    size += getsize(root->right);
    return size;
}

void dfs1(TreeNode* root, int d, unordered_map<TreeNode*, int>& depth,
          unordered_map<TreeNode*, vector<TreeNode*>>& dp, TreeNode* parent) {
    if (root == NULL)
        return;
    dp[root].push_back(parent);
    depth[root] = d;
    dfs1(root->right, d + 1, depth, dp, root);
    dfs1(root->left, d + 1, depth, dp, root);
    return;
}

void dfs2(unordered_map<TreeNode*, vector<TreeNode*>>& dp, TreeNode* root,
          int LOG) {

    if (root == NULL)
        return;
    dp[root].resize(LOG);
    for (int i = 1; i < LOG; i++) {
        // now we need to find the ith parent so for that i can do the i-1
        // parent of i-1 this root
        TreeNode* inter = dp[root][i - 1];
        if (inter == NULL)
            dp[root][i] = NULL;
        else
            dp[root][i] = dp[dp[root][i - 1]][i - 1];
    }

    dfs2(dp, root->left, LOG);
    dfs2(dp, root->right, LOG);

    return;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        unordered_map<TreeNode*, vector<TreeNode*>> dp;
        unordered_map<TreeNode*, int> depth;
        dfs1(root, 0, depth, dp, NULL); // this will initialise the dpeth map
        int n = getsize(root);
        int LOG = log2(n) + 1;
        // so log is the max numer of parent that i am gonna store like i am
        // going to store 2 pow LOG ansester for any node at max
        dfs2(dp, root, LOG);

        // so all the parent storing is done

        int diff = abs(depth[q] - depth[p]);
        if (depth[p] > depth[q]) {

            for (int i = 0; i < 32; i++) {
                if ((1 << i) & diff) {
                    p = dp[p][i];
                }
            }

        } else {

            for (int i = 0; i < 32; i++) {
                if ((1 << i) & diff) {
                    q = dp[q][i];
                }
            }
        }

        // now both the p and q will be n the same level
        if (p == q)
            return q;

        for (int i = LOG - 1; i >= 0; i--) {
            // check for the farthest parent that is not similar
            if (dp[p][i] != dp[q][i]) {
                p = dp[p][i];
                q = dp[q][i];
            }
        }
        return dp[p][0];
    }
};