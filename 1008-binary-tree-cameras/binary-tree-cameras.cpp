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

    // void traverse(TreeNode*root,bool check,int & camera){
        
    //     if(root==NULL)return;
    //     if(check==true && root->left!=NULL && root->right!=NULL)camera++;
    //     bool new_check=!check;
    //      traverse(root->left,new_check,camera);
    //      traverse(root->right,new_check,camera);
    //     return ;
        

    // }

        //0->this node needs camera 
        //1-> this node has a camera 
        //2-> this node is covered with someoneelse camera
    int traverse(TreeNode*root,int & camera){
        if(root==NULL)return 2;
        
        int leftAns=traverse(root->left,camera);
        int rightAns=traverse(root->right,camera);

        if(leftAns==0  || rightAns==0 ) {
            camera++;
            return 1;//both childen need cam so the parent has the cam now 
        }
        else if(leftAns ==2 && rightAns==2){
            
            return 0;//parent is not covered so it gets its own cam 
        }
        else if(leftAns==1 || rightAns==1){
            return 2;//now the parent node is covered with the children cam
        }
        return 0;//fallback
         
    }

    int minCameraCover(TreeNode* root) {

        //SO I NEED TWO thing first is the total count of the cameras and second is the check bool which is initially false and on each itereation it will be changed means check=!check  like if true on node A then false on  node children 
        // wheneveer we encountered the check==true this means there is a need for the camerea there inc the camera cnt by 1 simple 

        // int camera=0;
        // bool check=false;
        // if(root->left==NULL && root->right==NULL)return 1;
        
        // traverse(root,check,camera);
        //  return camera;

        // what if each node give me how much total cam it need below it 

        //0->this node needs camera 
        //1-> this node has a camera 
        //2-> this node is covered with someoneelse camera

        // so if either child return 1 this means the parent can retun 2 
        // if both return 2 meand parent return 0 and add the global cnt of camere
        // if both children return 0 then parent need the cam camrea++ and parent retrun 1

         int camera=0;
         
         int rootStatus=traverse(root,camera);
         if(rootStatus==0)camera++;
         return camera;

        
    }
};