class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //what i am thinking is that i will first find the size of the connected component and then check that if it has to be complete then there has to be indegree of size-1 of all the node to be complete 
        vector<bool>visited(n,false);
        int ans=0;
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);//what is the indegree=outdegree of node 
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
               
                int curr_size=1;
                queue<int>q;
                vector<int>temp;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                        int front=q.front();
                        temp.push_back(front);
                        q.pop();
                        for(auto neig:adj[front]){
                            if(!visited[neig]){
                                q.push(neig);
                                curr_size++;
                                visited[neig]=true;
                            }
                        }                    
                }

                // now we have one connected component in the temp 
                bool flag=true;
                for(auto i:temp){
                    if(degree[i]!=curr_size-1)flag=false;
                }
                if(flag)ans++;

            }
        }




        return ans;
    }
};