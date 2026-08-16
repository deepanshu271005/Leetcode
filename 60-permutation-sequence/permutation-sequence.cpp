class Solution {
public:
    void f(int n, string& s, string& curr, vector<string>& store,
           vector<bool>& visited, int idx) {
        if (curr.size() == n) {
            store.push_back(curr);
            return;
        }
        if (idx == n)
            return;

        if (visited[idx] == false) {
            visited[idx] = true;
            curr.push_back(s[idx]);
            f(n, s, curr, store, visited, 0);
            visited[idx] = false;
            curr.pop_back();
        }
        f(n, s, curr, store, visited, idx + 1);
        return;
    }

    string getPermutation(int n, int k) {
        // first  i will try to build all the valid permutation

        vector<string> store;
        vector<bool> visited(n + 1, false);
        string curr = "";
        string s = "";
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        //   for(auto i:s)cout<<s;
        //   cout<<endl;
        f(n, s, curr, store, visited, 0);
        //  for(auto i:store)cout<<i;

        return store[k - 1];
    }
};