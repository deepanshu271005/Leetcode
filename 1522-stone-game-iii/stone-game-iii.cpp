class Solution {
public:
    string stoneGameIII(vector<int>& nums) {

        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // // dp[i][j]represent the max score the the player first to move can
        // get
        // // i<n 77 j<n
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (j < i)
        //             continue;
        //         if (i == j) {
        //             dp[i][j] = nums[i];
        //         }
        //     }
        // }

        // vector<int> prefix(n);
        // prefix[0] = nums[0];
        // for (int i = 1; i < n; i++) {
        //     prefix[i] = prefix[i - 1] + nums[i];
        //     ;
        // }

        // // for each stage calc i will need the dp[i+1][j] so the ith loop
        // will
        // // go back
        // // out of bound problem
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = n - 1; j > i; j--) {
        //       int op1 = -1e9, op2 = -1e9, op3 = -1e9;
        //         // For op1
        //         if (i + 1 >= n) {
        //             op1 = nums[i];
        //         } else {
        //             op1 = nums[i] + (prefix[j] - prefix[i]) - dp[i + 1][j];
        //         }

        //         // For op2
        //         if (i + 1 < n && i + 2 >= n) {
        //             op2 = nums[i] + nums[i + 1];
        //         } else if (i + 2 < n) {
        //             op2 = (nums[i] + nums[i + 1]) +
        //                   (prefix[j] - prefix[i + 1]) - dp[i + 2][j];
        //         }

        //         // For op3
        //         if (i + 2 < n && i + 3 >= n) {
        //             op3 = nums[i] + nums[i + 1] + nums[i + 2];
        //         } else if (i + 3 < n) {
        //             op3 = (nums[i] + nums[i + 1] + nums[i + 2]) +
        //                   (prefix[j] - prefix[i + 2]) - dp[i + 3][j];
        //         }
        //         dp[i][j] = max({op1, op2, op3});
        //     }
        // }

        // // now the dp[0][n-1] will have the max score that first player can
        // get int p1score = dp[0][n - 1]; int p2score = prefix[n - 1] -
        // p1score; if (p1score > p2score)
        //     return "Alice";
        // if (p1score < p2score)
        //     return "Bob";
        // return "Tie";

        int n = nums.size();
        // the 2-D dp will give MLE
        // dp[i]->> max score that we can get from i to end of the array for
        // first player
        //  i will divide this question in2 segement 1 is if size<=3 and other
        //  is >3;

        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            ;
        }

        if (n <= 3) {
             vector<int>dp(n);
             dp[n-1]=nums[n-1];
            if(n>1) dp[n-2]=max(nums[n-2]+(prefix[n-1]-prefix[n-2])-dp[n-1],nums[n-2]+nums[n-1]);
            if(n>2) dp[n-3]=max({nums[n-3]+nums[n-2]+nums[n-1],nums[n-3]+nums[n-2]+(prefix[n-1]-prefix[n-2])-dp[n-1],nums[n-3]+(prefix[n-1]-prefix[n-3])-dp[n-2]});
             int p1=dp[0];
             int p2=prefix[n-1]-p1;
           // for(auto i:dp)cout<<i<<"   ";
         //  cout<<p1<<"   "<<p2;
            if (p1 > p2)
                return "Alice";
            if (p1 < p2)
                return "Bob";
            return "Tie";
        }
        vector<int>dp(n,0);
        //dp[i] -> max score from i to n that first playing can get 
        //base case
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-2],nums[n-2]+nums[n-1]);
        dp[n-3]=max({nums[n-3],nums[n-3]+nums[n-2]+nums[n-1],nums[n-3]+nums[n-2]});
        for(int i=n-4;i>=0;i--){
            int opt1=nums[i]+(prefix[n-1]-prefix[i])-dp[i+1];
            int opt2=nums[i]+nums[i+1]+(prefix[n-1]-prefix[i+1])-dp[i+2];
            int opt3=nums[i]+nums[i+1]+nums[i+2]+(prefix[n-1]-prefix[i+2])-dp[i+3];
            dp[i]=max({opt1,opt2,opt3});
        }
 
     int p1=dp[0];
     int p2=prefix[n-1]-p1;
     if (p1 > p2)
                return "Alice";
            if (p1 < p2)
                return "Bob";
            return "Tie";


    }
};