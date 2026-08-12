class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ones(n, vector<int>(m, 0));
        // ones[i][j]-> number of 1 form 0,0 to this point square
        ones[0][0] = matrix[0][0] - '0';
        for (int i = 1; i < n; i++) {
            ones[i][0] = (matrix[i][0] - '0') + ones[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            ones[0][i] = (matrix[0][i] - '0') + ones[0][i - 1];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                ones[i][j] = (matrix[i][j] - '0') + ones[i - 1][j] +
                             ones[i][j - 1] - ones[i - 1][j - 1];
            }
        }

        // now the ones is completed
        // for finding the square form one point we need to jsut subtract both
        // the i and the j col simuntanuosly to make a square till it goes out
        // of bounds
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    continue; // this cell cannot be included in the ans;
                int x = i;
                int y = j;

                while (x >= 0 && y >= 0) {
                    // Safely get top, left, and top-left values. If the index
                    // is -1, treat it as 0.
                    int top = (x > 0) ? ones[x - 1][j] : 0;
                    int left = (y > 0) ? ones[i][y - 1] : 0;
                    int topLeft = (x > 0 && y > 0) ? ones[x - 1][y - 1] : 0;

                    int totalOnes = ones[i][j] - top - left + topLeft;

                    int sideLength = (i - x + 1);
                    int squareSize = sideLength * sideLength;

                    if (totalOnes == squareSize) {
                        ans = max(ans, squareSize);
                        x--;
                        y--;
                    } else {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};