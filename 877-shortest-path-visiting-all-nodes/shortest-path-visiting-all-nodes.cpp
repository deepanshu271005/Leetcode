class Solution {
public:
    struct data {
        int node;
        int mask;
        int pathlength;
    };

    int shortestPathLength(vector<vector<int>>& graph) {

        // adj list is already given

        // we will start the multisource bfs

        int n = graph.size();
        int ans = 0;
        queue<data> q;
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        for (int i = 0; i < n; i++) {
            int node = i;
            int mask = 1 << i;
            int pathlength = 0;
            q.push({node, mask, pathlength});
        }

        // now the queue contain all the starting point to start for the multi
        // source BFS

        while (!q.empty()) {
            data front = q.front();
            int curr_node = front.node;
            int curr_mask = front.mask;
            int curr_length = front.pathlength;
            int setbits = 0;
            for (int i = 0; (1 << i) < curr_mask; i++) {
                if (curr_mask & (1 << i))
                    setbits++;
            }
            if (setbits == n) {
                ans = curr_length;
                break;
            }
            q.pop();
            for (auto i : graph[curr_node]) {
                int next_node = i;
                int next_mask = curr_mask | 1 << i;
                int next_length = curr_length + 1;
                if (dp[next_node][next_mask] != -1)
                    continue; // that means that this node is already visiuted
                              // with better path
                q.push({next_node, next_mask, next_length});
                dp[next_node][next_mask]=next_length;
            }
        }

        return ans;
    }
};