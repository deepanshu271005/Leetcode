class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool bfs(vector<int>& source, vector<int>& target, unordered_set<long long>& blocks) {
        unordered_set<long long> visited;
        queue<pair<int, int>> q;
        
        q.push({source[0], source[1]});
        visited.insert((long long)source[0] * 1000000 + source[1]);
        
        int distinct = 0;
        
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            distinct++;
            
            if (x == target[0] && y == target[1]) return true;
            if (distinct > 19900) return true;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < 1000000 && ny >= 0 && ny < 1000000) {
                    long long hash = (long long)nx * 1000000 + ny;
                    if (blocks.find(hash) == blocks.end() && visited.find(hash) == visited.end()) {
                        visited.insert(hash);
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blocks;
        for (auto& b : blocked) {
            blocks.insert((long long)b[0] * 1000000 + b[1]);
        }
        
        return bfs(source, target, blocks) && bfs(target, source, blocks);
    }
};