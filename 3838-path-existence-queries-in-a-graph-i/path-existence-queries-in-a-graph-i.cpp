class Solution {
public:
    vector<int> parent;

    int getparent(int t) {
        if (parent[t] == t)
            return t;

        return parent[t] = getparent(parent[t]);
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        // so this is the question of dsu as i just need to know which component
        // are connected

        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // at initial every node is self parent of itself
        }

        for(int i=1;i<n;i++){
            //now i have to check if the adjacent element are elible to connect to each other 
            int adj=i-1;
            int curr=i;
            int p_curr=getparent(curr);
            int p_adj=getparent(adj);
            if(p_curr==p_adj)continue;//already connected
            else {
                if(abs(nums[curr]-nums[adj])<=maxDiff) parent[curr]=p_adj;
                 }
        }
           
           vector<bool>ans;

        //now we have the connected component together 
        for(const auto& i : queries){
             int src=i[0];
             int dest=i[1];
             if(parent[src]==parent[dest])ans.push_back(true);
             else ans.push_back(false);
        }
        return ans;

    }
};