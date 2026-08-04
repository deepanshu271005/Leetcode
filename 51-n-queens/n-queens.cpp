class Solution {
public:
    bool validRow(vector<string>& board, int row) {
        if (row < 0 || row >= board.size())
            return false;
        for (int i = 0; i < board[0].size(); i++) {
            if (board[row][i] == 'Q')
                return false;
        }
        return true;
    }
    bool validCol(vector<string>& board, int col) {
        if (col < 0 || col >= board.size())
            return false;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        return true;
    }
    bool validCross(vector<string>& board, int row, int col) {
        int n = board.size();

        // Top-Left Diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q')
                return false;
        }

        // Top-Right Diagonal
        for (int r = row, c = col; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == 'Q')
                return false;
        }

        // Bottom-Left Diagonal
        for (int r = row, c = col; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 'Q')
                return false;
        }

        // Bottom-Right Diagonal
        for (int r = row, c = col; r < n && c < n; r++, c++) {
            if (board[r][c] == 'Q')
                return false;
        }

        return true;
    }

    bool check(vector<string>& board, int x, int y) {
        if (validRow(board, x) && validCol(board, y) &&
            validCross(board, x, y)) {
            return true;
        }
        return false;
    }

    void backtrack(vector<string>& board, int x, int y, int cnt,
                   vector<vector<string>>& ans) {
        int n = board.size();
        if (cnt == 0) {
            ans.push_back(board);
            return;
        }
        if (x >= board.size() || x < 0 || y >= board.size() || y < 0)
            return;

        // check if it is valid to have a queen at this index or not
        //  for (auto i : board) {
        //     cout << i << endl;
        // }
        // cout<<"count:"<<cnt;
        // cout<<endl;
        // cout<<endl;

        for (int i = x + 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == x && j == y)
                    continue;
                if (check(board, i, j)) {
                    board[i][j] = 'Q';
                    backtrack(board, i, j, cnt - 1, ans);
                    board[i][j] = '.';
                }
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        vector<vector<string>> ans;
        string s;
        for (int i = 0; i < n; i++) {
            s.push_back('.');
        }
        for (int i = 0; i < n; i++) {
            board.push_back(s);
        }

        // for (auto i : board) {
        //     cout << i << endl;
        // }
        // cout<<endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = 'Q';
                backtrack(board, i, j, n - 1, ans);
                board[i][j] = '.';
            }
        }

        return ans;
    }
};