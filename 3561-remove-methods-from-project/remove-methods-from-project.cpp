class Solution {
public:
 

     bool canRemove(vector<vector<int>>&adj,int method,vector<bool>&marked){
        for(auto i:adj[method]){
            if(marked[i]==false)return false;
          }
          return true;
     }

     void dfs(vector<vector<int>>&adj,int method,vector<bool>&marked){
        
        marked[method]=true;//this method got bugged
        for(auto i:adj[method]){
            if(!marked[i])dfs(adj,i,marked);
        }
        return;
     }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(n);
        vector<bool>marked(n,false);
        for(auto i:nums){
            int s=i[0];
            int e=i[1];
            adj1[s].push_back(e);
            adj2[e].push_back(s);
        }

     // now the adj 1 conatain that from 'a' where can i go 
    //adj2 has that from where can i come to 'a'

      dfs(adj1,k,marked);
      // all the element directly or indirectly that are connected are now marked 
       vector<int>ans;vector<int>temp;
       for(int i=0;i<n;i++)ans.push_back(i);
       for(int i=0;i<n;i++){
        if(marked[i]){
                //this needs to be removed
                if(!canRemove(adj2,i,marked))return ans;
        }
        else temp.push_back(i);//this method need not to be removed
       }
             return temp;
    }
};