class Solution {
public:
    void f(map<string, multiset<string>>& adj, vector<string>& ans, string curr,
           int n) {

        if (ans.size() == n + 1)
            return;
        //   for(auto i:adj[curr]){
        //       string next =i;
        //     adj[curr].erase(next);
        //      f(adj,ans,next,n);
        //      }   // this is causing runtime error as the auto loop has its
        //      iterator but the deleting will cause the index to shift
        while (!adj[curr].empty()) {
            string next = *adj[curr].begin();
            adj[curr].erase(adj[curr].begin());
            f(adj, ans, next,n);
        }
        ans.push_back(curr);
        return;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> adj;
        for (auto i : tickets) {
            adj[i[0]].insert(i[1]);
        }

        //   for(auto i:adj){
        //       sort(i.second.begin(),i.second().end());
        //   }

        vector<string> ans;
        // for (auto i : adj) {
        //     cout << i.first << ":";
        //     for (auto j : i.second) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        f(adj, ans, "JFK", tickets.size() + 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]