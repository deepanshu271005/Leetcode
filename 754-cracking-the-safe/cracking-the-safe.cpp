class Solution {
public:
    void f(int n, int k, unordered_map<string, bool>& m, string& curr) {
        if (curr.size() == n) {
            m[curr] = false;
            return;
        }

        for (int i = 0; i < k; i++) {
            curr += i + '0';
            f(n, k, m, curr);
            curr.pop_back();
        }
        return;
    }

    void helper(int n, int k, unordered_map<string, bool>& m, string& curr,
                int cnt, string& ans) {

        //  If we already found the answer in stop
        if (ans != "")
            return;

        // We visited all nodes Save to ans and return
        if (cnt == 0) {
            ans = curr;
            return;
        }

        if (curr.size() >= m.size() * n)
            return;

        for (int i = 0; i < k; i++) {
            curr += i + '0';
            string temp = "";

            if (curr.size() >= n) {
                temp = curr.substr(curr.size() - n, n);
            }
            if (m.find(temp) != m.end() && m[temp] == false) {
                m[temp] = true;

                // Only recurse if we are actually making progress
                helper(n, k, m, curr, cnt - 1, ans);

                // Backtrack
                m[temp] = false;
            }
            curr.pop_back();
        }
        return;
    }

    string crackSafe(int n, int k) {
        // first i need to get all the possible string that can be ans
        unordered_map<string, bool> m;
        string curr = "";
        f(n, k, m, curr);
        // so now the m contain all the valid possible string that can be the
        // ans
        //  for(auto i:m)cout<<i.first<<" "; // for checking waht m has

        curr = string(n, '0');   // Start with "00" instead of ""
        m[curr] = true;          // Mark "00" as visited
        int left = m.size() - 1; // We already visited 1 node
        string ans = "";
        helper(n, k, m, curr, left, ans);
        return ans;
    }
};