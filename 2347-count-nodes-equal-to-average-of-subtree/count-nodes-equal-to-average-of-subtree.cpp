/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    pair<int,int> f(TreeNode*root,int &cnt){
        if(root==NULL)return {0,0};//the sum of the subtree is zero and the number of nodes in the subtree is also zero 
        auto [left_sum,left_size]=f(root->left,cnt);
        auto [right_sum,right_size]=f(root->right,cnt);
        int t_sum=left_sum+right_sum+root->val;
        int t_size=left_size+right_size+1;
        if(root->val==(t_sum/t_size))cnt++;
        return {t_sum,t_size};
    }
 
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
          auto it = f(root,cnt);
        return cnt;
    }
};