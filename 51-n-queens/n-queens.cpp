class Solution {
public:
    void backtrack(vector<string>& board, int row, int n, 
                   vector<bool>& cols, vector<bool>& antiDiag, vector<bool>& mainDiag, 
                   vector<vector<string>>& ans) {
         if (row == n) {
            ans.push_back(board);
            return;
        }

         for (int col = 0; col < n; col++) {
            int antiId = row + col;
            int mainId = row - col + n - 1;

             if (cols[col] || antiDiag[antiId] || mainDiag[mainId]) {
                continue; 
            }

             board[row][col] = 'Q';
            cols[col] = true;
            antiDiag[antiId] = true;
            mainDiag[mainId] = true;

             backtrack(board, row + 1, n, cols, antiDiag, mainDiag, ans);

             board[row][col] = '.';
            cols[col] = false;
            antiDiag[antiId] = false;
            mainDiag[mainId] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
         vector<bool> cols(n, false);
        vector<bool> antiDiag(2 * n - 1, false);
        vector<bool> mainDiag(2 * n - 1, false);

         backtrack(board, 0, n, cols, antiDiag, mainDiag, ans);

        return ans;
    }
};