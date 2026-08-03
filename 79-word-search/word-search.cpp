class Solution {
public:
    bool f(vector<vector<char>>& board, string& word, int x, int y,
           string& temp, vector<vector<bool>>& visited) {
        // cout << temp << " -> ";
        //  edge case
        if (temp == word) {
            return true;
        }
        if (temp.size() >= word.size() || x >= board.size() ||
            y >= board[0].size() || x < 0 || y < 0) {
            return false; // invlaid index
        }

        // form a index i can go right,left and up down
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        if (visited[x][y] || board[x][y] != word[temp.size()])
            return false;
        temp.push_back(board[x][y]);
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (f(board, word, nx, ny, temp, visited))
                return true;

            // if(f(board,word,nx,ny,temp,visited))return true;
        }
        temp.pop_back();
        visited[x][y] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        string temp;
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0])
                    continue;
                if (f(board, word, i, j, temp, visited))
                    return true;
            }
        }
        return false;
    }
};