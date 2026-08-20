class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited,
             vector<vector<int>>& ans, vector<int>& currpath, int currnode) {
        currpath.push_back(currnode);
        visited[currnode] = 1;

        if (currnode == adj.size() - 1) {
            ans.push_back(currpath);
            currpath.pop_back();
            visited[currnode] = 0;
            return;
        }

        for (auto i : adj[currnode]) {
            if (visited[i] != 1) {
                dfs(adj, visited, ans, currpath, i);
                
            }
        }
         
       currpath.pop_back();
       visited[currnode]=0;
      

        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int n = adj.size(); // 0 to n-1

        // dfs
        vector<int> visited(n, 0);
        vector<vector<int>> ans;
        vector<int> currpath;
        dfs(adj, visited, ans, currpath, 0);
        return ans;
    }
};