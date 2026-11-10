class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        
        vector<int>dp(n+1,-1);
        dp[0]=0;
        //if a stair in unreachable it is -1 
        for(int i=1;i<=n;i++){
            int ans=INT_MAX;
            int currstair=i;
            int laststair=i-1;
            if(laststair>=0){
                ans=min(ans,dp[laststair]+cost[currstair-1]+(currstair-laststair)*(currstair-laststair));                    
            }
            laststair=i-2;
            if(laststair>=0){
                ans=min(ans,dp[laststair]+cost[currstair-1]+(currstair-laststair)*(currstair-laststair));                    
            }
            laststair=i-3;
            if(laststair>=0){
                ans=min(ans,dp[laststair]+cost[currstair-1]+(currstair-laststair)*(currstair-laststair));                    
            }
            if(ans==INT_MAX){
                //this node is unreachable 
            }
            else dp[i]=ans;
        }

        return dp[n];

    }
};