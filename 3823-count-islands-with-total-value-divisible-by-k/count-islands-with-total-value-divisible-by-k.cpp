class Solution {
public:

    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    long long dfs(int x, int y, vector<vector<int>>& grid,
            vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = grid[x][y];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny]>0) {
                visited[nx][ny] = true;
                sum += dfs(nx, ny, grid, visited);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]>0){
                    visited[i][j]=true;
                    long long sum=dfs(i,j,grid,visited);
                    if(sum%k==0)cnt++;
                }
            }
        }
        return cnt;
    }
};