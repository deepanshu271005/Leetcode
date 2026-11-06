class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Sort logs by time (logs[i][1] is time, logs[i][0] is server_id)
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Store queries with their original indices so we can answer them in sorted order
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        
        vector<int> server_freq(n + 1, 0);
        int active_servers = 0;
        int l = 0, r = 0;
        
        for (auto& q : sorted_queries) {
            int query_time = q.first;
            int orig_idx = q.second;
            int window_start = query_time - x;
            int window_end = query_time;
            
            // Expand right pointer to include all logs <= window_end
            while (r < logs.size() && logs[r][1] <= window_end) {
                int server_id = logs[r][0];
                if (server_freq[server_id] == 0) {
                    active_servers++;
                }
                server_freq[server_id]++;
                r++;
            }
            
            // Shrink left pointer to exclude logs < window_start
            while (l < r && logs[l][1] < window_start) {
                int server_id = logs[l][0];
                server_freq[server_id]--;
                if (server_freq[server_id] == 0) {
                    active_servers--;
                }
                l++;
            }
            
            ans[orig_idx] = n - active_servers;
        }
        
        return ans;
    }
};