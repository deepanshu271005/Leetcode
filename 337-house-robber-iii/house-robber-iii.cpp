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
    map<TreeNode*, pair<int, int>>
        dp; // fisrt int is the dp[0]state and the second one is the dp[1]
            // adjacent looted state
    void f(TreeNode* root) {
        if (root == NULL) {
            dp[root] = {0, 0};
            return;
        }
        f(root->left);
        f(root->right);

        // suppose that adjacent is not looted both the adj
        int ans1 = root->val + (dp[root->left].first + dp[root->right].first);
        int ans2 =
            max(dp[root->left].second, dp[root->left].first) +
            max(dp[root->right].second,
                dp[root->right]
                    .first); // because if the current node is not taken then
                             // both the left and the rifht can be looted
        // cout<<ans1<<" "<<ans2;
        dp[root] = {ans2, ans1};
        return;
    }

    int rob(TreeNode* root) {
        // i will have 2 d dp that is
        // dp[i][0]-> wiull tell the max amt i can get till node i if the two
        // directly linked houses are not looted dp[i][1]-> wiull tell the max
        // amt i can get till node i if one of the two directly  linked houses
        // are not looted

        f(root);
        // cout << dp.size();
        // for (auto i : dp) {

        //     cout << " " << i.second.first << " " << i.second.second << endl;
        // }
        return max(dp[root].first, dp[root].second);
    }
};