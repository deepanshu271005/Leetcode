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

      void f(TreeNode*root,int &cnt,int maxval){
        if(root==NULL)return;
    
        if(maxval<=root->val){
           cnt++;//found a good node
        } 
        maxval=max(maxval,root->val);
        f(root->left,cnt,maxval);
        f(root->right,cnt,maxval);

       return;

      }

    int goodNodes(TreeNode* root) {
        if(root==NULL)return NULL;
        int cnt=0;

        f(root,cnt,INT_MIN);
        return  cnt;
    }
};