
class Solution {
 
    class node{
     public:
        node* one;
        node* zero;
        bool f;
        node()
        {
            one = NULL;
            zero = NULL;
            f = 0;
        }
    };

    class tries{
        node* root;
    public:

      tries(){
        root=new node();
      }
         
         void insert(int n){
             node* cur = root;
            for(int i=31;i>=0;i--){
                if(n&(1<<i)){
                    if(cur->one == NULL)
                    {
                        cur->one = new node();
                        cur = cur->one;
                    }
                    else
                    {
                        cur = cur->one;
                    }   
                }
                else{
                    if(cur->zero == NULL)
                    {
                        cur->zero = new node();
                        cur = cur->zero;
                    }
                    else
                    {
                        cur = cur->zero;
                    }   
                }
                if(i == 0)cur->f=1;

            }

         }
         
         int maxor(int n){
             node*curr=root;
            for(int i=31;i>=0;i--){
                if(n&(1<<i)){
                    if(curr->zero!=NULL){
                        curr=curr->zero;
                    }
                    else {
                        curr=curr->one;
                        n=n^(1<<i);
                     }

                }
                else{
                    if(curr->one!=NULL){
                        curr=curr->one;
                        n=n^(1<<i);
                    }
                    else {
                        curr=curr->zero;
                    }

                }
            }

              return n;
         }

        
     };
  
public:
    int findMaximumXOR(vector<int>& nums) {
        tries t;
        for(auto i:nums){
            t.insert(i);
        }

       int ans=0;
       for(int i=0;i<nums.size();i++){
           ans=max(ans,t.maxor(nums[i]));
           cout<<t.maxor(nums[i])<<" "<<nums[i]<<endl;
       }
     return ans;
    }
};