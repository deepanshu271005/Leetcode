class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    class Node {
    public:
        vector<Node*> store;
        bool f;
        Node() {
            store.resize(26);
            for (int i = 0; i < 26; i++) {
                store[i] = NULL;
                f = false;
            }
        }
    };

    class Tries {
        Node* root = new Node();

    public:
        void insert(string s) {
            Node* curr = root;
            for (auto i : s) {
                if (curr->store[i - 'a'] != NULL) {
                    curr = curr->store[i - 'a'];
                } else {
                    curr->store[i - 'a'] = new Node();
                    curr = curr->store[i - 'a'];
                }
            }
            curr->f = true; // this word exist
        }

        bool checkfinal(string s) {
            // this function will check if the string "s" exist or not
            Node* curr = root;
            int it = 0;
            while (it < s.size()) {
                if (curr->store[s[it] - 'a'] == NULL) {
                    // this path does not exist
                    return false;
                } else {
                    curr = curr->store[s[it] - 'a'];
                    it++;
                }
            }
            if (curr->f) {
                curr->f = false;
                return true;
            }
            return false;
        }

        bool checkpath(string s) {
            Node* curr = root;
            int it = 0;
            while (it < s.size()) {
                if (curr->store[s[it] - 'a'] == NULL) {
                    // this path does not exist
                    return false;
                } else {
                    curr = curr->store[s[it] - 'a'];
                    it++;
                }
            }
            return true; // this path exist
        }
    };

    void f(int x, int y, vector<vector<bool>>& visited, vector<string>& ans,
           Tries* t, string& curr, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (x >= n || y >= m || x < 0 || y < 0) {
            return;
        }

        if (t->checkfinal(curr))
            ans.push_back(curr);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < n && ny < m && nx >= 0 && ny >= 0 && !visited[nx][ny] &&
                t->checkpath(curr + board[nx][ny])) {
                // expoling this path is valid
                visited[nx][ny] = 1;
                curr += board[nx][ny];
                f(nx, ny, visited, ans, t, curr, board);
                visited[nx][ny] = 0;
                curr.pop_back();
            }
        }

        return;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> ans;
        // i am thinking of making a trie in this question and then i will only
        // move to the path in whcic do exist in the trie

        Tries* t = new Tries();
        for (auto i : words) {
            t->insert(i);
        }

        // cout<<t->checkpath("ea")<<endl;  // trie is working completely as
        // wanted
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                string temp = "";
                temp += board[i][j];
                if (t->checkpath(temp)) {
                    visited[i][j] = 1;
                    f(i, j, visited, ans, t, temp, board);
                    visited[i][j] = 0;
                }
            }
        }

        return ans;
    }
};