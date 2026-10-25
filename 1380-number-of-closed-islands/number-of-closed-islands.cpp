class DSU {
public:
    vector<int> parent, size;
    vector<bool> isClosed; 

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        isClosed.resize(n, true);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int fp(int node) {
        if (parent[node] == node) return node;
        return parent[node] = fp(parent[node]); 
    }

    void unsize(int u, int v) {
        int rootU = fp(u);
        int rootV = fp(v);
        if (rootU == rootV) return;

        if (size[rootU] > size[rootV]) {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
            isClosed[rootU] = isClosed[rootU] && isClosed[rootV];
        } else {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
            isClosed[rootV] = isClosed[rootV] && isClosed[rootU];
        }
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        DSU d(rows * cols);

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    int current1D = i * cols + j;
                    
                    if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                        d.isClosed[d.fp(current1D)] = false;
                    }

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 0) {
                            d.unsize(current1D, ni * cols + nj);
                        }
                    }
                }
            }
        }

        int closedIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    int root = d.fp(i * cols + j);
                    if (root == i * cols + j && d.isClosed[root]) {
                        closedIslands++;
                    }
                }
            }
        }

        return closedIslands;
    }
};