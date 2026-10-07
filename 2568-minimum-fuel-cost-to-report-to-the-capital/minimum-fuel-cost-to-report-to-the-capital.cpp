class Solution {
public:
    pair<int, long long> dfs(vector<vector<int>>& adj, int node,
                             vector<int>& visited, int cap) {
        int people = 1;
        long long fuel = 0;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = 1;
                auto [childpeople, childfuel] = dfs(adj, i, visited, cap);
                visited[i] = false;
                people += childpeople;
                fuel += ((childpeople % cap == 0) ? (childpeople / cap)
                                                  : ((childpeople / cap) + 1)) +
                        childfuel;
            }
        }
        return {people, fuel};
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n, vector<int>());
        for (auto i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(n, false);
        visited[0] = true;
        return dfs(adj, 0, visited, seats).second;
    }
};