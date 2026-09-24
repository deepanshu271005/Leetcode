class Solution {
public:
    int dfs1(vector<vector<int>>& adj, int node, int parent, vector<int>& sz) {
        bool flag = true;
        for (auto neig : adj[node]) {
            if (neig == parent)
                continue;
            sz[node] += dfs1(adj, neig, node, sz);
            flag = false;
        }
        if (flag)
            return sz[node] = 1;
        sz[node] += 1;
        return sz[node];
    }

    void dfs2(vector<vector<int>>& adj, vector<int>& dist, int node, int parent,
              int currdis) {
        dist[node] = currdis;
        for (auto i : adj[node]) {
            if (i == parent)
                continue;
            dfs2(adj, dist, i, node, currdis + 1);
        }
        return;
    }

    void dfsReroot(vector<vector<int>>& adj, vector<int>& sz, vector<int>& ans,
                   int node, int parent, int n) {
        for (auto nei : adj[node]) {

            if (nei == parent)
                continue;

            ans[nei] = ans[node] + n - 2 * sz[nei];

            dfsReroot(adj, sz, ans, nei, node, n);
        }
        return ;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // so what i want is for each node i want that what is no of nodes in
        // the subtree of this node so that i can know that what is the
        // contribution of this edge in the total ans for this node suppose the
        // tree is rooted at the 0 and then cal these two thing for each node
        // that is the cnt of node in each subtree and the weight of the edge in
        // the ans that is simply the no of node in the subtree beacse we will
        // have to add this edge that many times only

        vector<int> sz(n, 0);

        vector<vector<int>> adj(n);
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        sz[0] = dfs1(adj, 0, -1, sz);
        // int cnt=0;
        // for (auto i : sz)
        //     cout << cnt++<<" "<<i << "    ";

        // okay so lets calc the ans for the 0 rooted tree

        vector<int> dist_from_root(n, 0);
        dfs2(adj, dist_from_root, 0, -1, 0);

        //  for(auto i:dist_from_root)cout<<i<<" ";

        vector<int> ans(n, 0);
        // final ans for the rooted tree
        int t = 0;
        for (auto i : dist_from_root)
            t += i;
        ans[0] = t;

        // now we will shift the root of the tree from 0 to each node(re rooting
        // and then update the ans with the help of the sz array);

        dfsReroot(adj,sz,ans,0,-1,n);

        return ans;
    }
};