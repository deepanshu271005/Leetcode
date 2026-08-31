class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        // so now dp[i]->stores the diff,cnt in the map
        // dp[i][j]=x so it define that upto i index and j diff how many (cnt)
        // subsequce are ending of len>=2

        // base case

        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                long long curr_diff = (long long)nums[i] - (long long)nums[j];

                // int cnt=dp[j][curr_diff];
                // ans+=cnt;
                // dp[i][curr_diff]+=cnt+1;
                auto it = dp[j].find(curr_diff);
                int cnt = (it != dp[j].end()) ? it->second : 0;

                ans += cnt;
                dp[i][curr_diff] += cnt + 1;
            }
        }

        //  for(auto i:dp){
        //     for(auto j:i)
        //     {
        //         // cout<<j.first<<" "<<j.second<<endl;
        //         ans+=max(0,j.second-2);
        //     }
        //     cout<<endl;
        //  }

        return ans;
    }
};