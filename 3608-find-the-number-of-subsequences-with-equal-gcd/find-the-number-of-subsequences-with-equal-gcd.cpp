#define MOD 1000000007
#include <numeric>
class Solution {
public: 

    int subsequencePairCount(vector<int>& nums) {
        
     //since the max value of n is 200 the max GCD can also be 200 max 
     //so i can store all the different combination in the map like map<int,vector<vector<int>>>m which will have all the possible combination of the int GCD 
     //but this has a problem that i cant tackle in this apprach is the disjoint one 
       
     //so the solution come up with the dp(2-D DP to be accurate)

     // dp[i][j]->> no of ways to make two seq 1 and 2 with the GCD i and j respectively 
     // for a element index we can either add it in first sequce and update i and vice versa or dont addd in either of them 
      
      vector<vector<int>>dp(201,vector<int>(201,0));
      dp[0][0]=1;//for two emty seq there is only one way 
      int n=nums.size();
      for(int i=0;i<n;i++){
        //so for this number i have 3 options 
        vector<vector<int>>next_dp;
        next_dp=dp;

        // ->> add this number in the first sequnce and update the gcd second and update or none 
         
        for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {
                    
                   
                    if (dp[g1][g2] == 0) continue; //unreachable state so no enefit in expolring this 
                    
                    // Choice 2: Add nums[i] to sequence 1
                    int new_g1 =  gcd(g1, nums[i]);
                    next_dp[new_g1][g2] = (next_dp[new_g1][g2] + dp[g1][g2]) % MOD;
                    
                    //  Choice 3: Add nums[i] to sequence 2
                    int new_g2 =  gcd(g2, nums[i]);
                    next_dp[g1][new_g2] = (next_dp[g1][new_g2] + dp[g1][g2]) % MOD;
                }
            }

            dp=next_dp;
      }
         
         int ans=0;
           for(int i=1;i<=200;i++){
            ans=(ans+dp[i][i])%MOD;
           }
         return ans;
    }
};