class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<vector<int>>& cnt,
             vector<vector<int>>& adj, vector<int>& group, int node,
             int parent) {

        cnt[node][group[node]]++; // this node cnt has been updated

        for (auto i : adj[node]) {
            if (i == parent)
                continue;
            dfs(edges, cnt, adj, group, i, node);

            for (int j = 1; j <= 20; j++) {
                cnt[node][j] += cnt[i][j];
            }
        }
        return;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges,
                               vector<int>& group) {
        // vector<vector<long long>> cost(n, vector<long long>(n, 1e18));
        // // base case for the cost array
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == j)
        //             cost[i][j] = 0;
        //     }
        // }
        // // now i have to relax all the edges one by one and  update the cost
        // // array for each succesfull edge relaxation update
        // for (auto i : edges) {
        //     int u = i[0];
        //     int v = i[1];
        //     cost[u][v] = min(cost[u][v], 1LL);
        //     cost[v][u] = min(cost[u][v], 1LL);
        // }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         for (int k = 0; k < n; k++) {
        //             if (cost[i][k] == 1e18 || cost[k][j] == 1e18)
        //                 continue; // the node k is unreachble from either of
        //                 one
        //                           // node
        //             cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        //         }
        //     }
        // }

        // //  for( auto i:cost){
        // //     for(auto j:i){
        // //         cout<<j<<" ";
        // //     }
        // //     cout<<endl;
        // //  }
        // long long ans = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (group[i] != group[j])
        //             continue;
        //         ans += cost[i][j];
        //     }
        // }
        // return ans;
        // // the problem is the time complexity due to the floyd warshal algo

        vector<vector<int>> cnt(
            n, vector<int>(
                   21, 0)); // cnt[i][j] -> will give how much nodes are below
                            // the ith node that belong to group j so the
                            // contribution of the edge above the 'i' can be
                            // simply multiplied directly by this because we
                            // need to cross this for each number that is there

        vector<vector<int>> adj(n);
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> total_count(21, 0);
        for (int i = 0; i < n; i++) {
            total_count[group[i]]++;
        }

        dfs(edges, cnt, adj, group, 0, -1);

        //  for(int i=0;i<n;i++){
        //     for(int j=1;j<21;j++){
        //         if(cnt[i][j]==0)continue;
        //         cout<<"Node:"<<i<<" Group:"<<j<<" "<<cnt[i][j]<<endl;
        //     }
        //  }
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= 20; j++) {
                long long inside = cnt[i][j];
                long long outside = total_count[j] - cnt[i][j];

                ans += inside * outside;
            }
        }

        return ans;
    }
};