class Solution {
public:
  
    bool f(vector<vector<int>>& edges,vector<int>&edge){
        int n=edges.size();  
         vector<vector<int>>adj(n+1,vector<int>());
         vector<int>indegree(n+1,0);
         for(auto i:edges){
            if(i==edge)continue;
            int p=i[0];
            int c=i[1];
            indegree[c]++;
            adj[p].push_back(c);
         }
         
         int root=-1;
         for(int i=1;i<=n;i++){
            if(indegree[i]==0)root=i;//break;
         }
         if(root==-1)return false;
         queue<int>q;
         vector<bool>visited(n+1,false);
         q.push(root);
         visited[root]=1;
         int cnt=1;
         while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto i:adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                    cnt++;
                }
            }
         }
         return cnt==n;

    }
 
 
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
         //acc to me this is the question of min spanning tree
         int n=edges.size();// 1 to n nodes are there 
    //      vector<vector<int>>adj(n+1,vector<int>());
    //      vector<bool>isparent(n+1,true);
    //      for(auto i:edges){
    //         int p=i[0];
    //         int c=i[1];
    //         adj[p].push_back(c);
    //         isparent[c]=false;
    //      }

    //      //so the node with no parent is the root node
    //       int root=1;
    //      for(int i=1;i<=n;i++){
    //             if(isparent[i]){root=i;break;}
    //      }
    //    //  cout<<root<<endl;

    //      //now i will start traversing from the root node and if i reach a node that can be reached with some other path to then this node is reductant 

    //      vector<bool>visited(n+1,false);
    //      vector<int>parent(n+1,-1);
    //      vector<vector<int>>ans;
    //      queue<int>q;
    //      q.push(root);
    //      parent[root]=root;
    //      visited[root]=true;
    //      while(!q.empty()){
    //         int front =q.front();
    //         q.pop();
    //         for(auto i:adj[front]){
    //             if(!visited[i]){
    //                 q.push(i);
    //                 visited[i]=true;
    //                 parent[i]=front;
    //             }
    //             else {
    //                 //this is reductant edge
    //                  ans.push_back({front,i});
    //                 if(adj[parent[i]].size()>1) ans.push_back({parent[i],i});//is disconnecting this valid or not 
    //             }
    //         }
    //      }
       
    //      //cout<<"Parent Node "<<root<<endl;
    //     // for(auto i:ans){
    //     //     for(auto j:i){
    //     //         cout<<j;
    //     //     }
    //     //     cout<<endl;
    //     // }
         
    //  if(ans.size()==1)return ans[0];
    //  // the ans is one of the two store in the ans array 
    // bool onetime=false;
    //  for(int i=n-1;i>=0;i--){
    //     if(edges[i]==ans[0] || edges[i]==ans[1]){
    //         if(onetime)return edges[i];
    //         if(f(edges,edges[i])){return edges[i];onetime=true;}
    //     }
    //  }
    //      return {};



      for(int i=n-1;i>=0;i--){
        if(f(edges,edges[i]))return edges[i];
      }
      return {};

    }
};