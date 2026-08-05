/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
       
        int makenum(string s,int&index){
            string temp;
            for(index;s[index]!=',';index++){
                     temp.push_back(s[index]);
            }
            index++;
            int n=stoi(temp);
               return n;

        }
       void makestring(TreeNode*root,string&s){
          queue<TreeNode*>q;
          q.push(root);
          TreeNode*temp=q.front();int size=q.size();
          while(!q.empty()){
             size=q.size();
            while(size--){
            if(temp==NULL){
                s.push_back('#');
                s+=',';
                q.pop();

            }
            else{
               s+=to_string(temp->val);
               s+=',';
               q.pop();
               q.push(temp->left);
               q.push(temp->right);
                 }
               temp=q.front();
            }
               
                 }
       }

            void buildtree(string s,TreeNode* &root){
                  queue<TreeNode*>q; int index=0;
                int num=makenum(s,index);
                 root=new TreeNode(num);
                 q.push(root);
                 
                 while(!q.empty()&&index<=s.size()-1){
                     
                     TreeNode*temp=q.front();
                    if(s[index]=='#'){
                        temp->left=NULL;
                        index+=2;
                    }
                    else{
                        num=makenum(s,index);
                    temp->left=new TreeNode(num);
                    q.push(temp->left);
                     
                    }
                    if(s[index]=='#'){
                        temp->right=NULL;
                        index+=2;
                    }
                    else{
                         num=makenum(s,index);
                        temp->right=new TreeNode(num);
                        q.push(temp->right);
                        

                    }
                    q.pop();
                  //  temp=q.front();

                 }



            }

    

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if(root==NULL){
            return s;
        }
         makestring(root,s);
          
          
            return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        for(auto i:data){
            cout<<i;
        }
        TreeNode*root=NULL;
      if(data.size()==0){
        return NULL;
      }
       buildtree(data,root);
       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));