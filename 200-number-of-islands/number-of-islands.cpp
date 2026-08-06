class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i,
             int j) {
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                    grid[nx][ny] == '1' && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]=='0' || visited[i][j]) {
                    continue;
                }
                bfs(grid, visited, i, j);
                ans++;
                // for (auto i : visited) {
                //     for (auto j : i) {
                //         cout << j << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl << endl;
            }
        }
        return ans;
    }
};