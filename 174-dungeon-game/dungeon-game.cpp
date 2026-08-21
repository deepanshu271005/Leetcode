class Solution {
public:
 
    int dfs(vector<vector<int>>&nums,int x,int y, vector<vector<int>>&dp){
        int n=nums.size();
        int m=nums[0].size();
        if(x<0 || y<0 || x>=n || y>=m)return INT_MAX;

        if(x==n-1 && y==m-1){
            return max(1,1-nums[x][y]);
        }
        if(dp[x][y]!=INT_MAX)return dp[x][y];
        int right=dfs(nums,x+1,y,dp);
        int left=dfs(nums,x,y+1,dp);
        int minhealth=min(right,left);
       
         return dp[x][y]=max(1,minhealth-nums[x][y]);
            
    }
  
    int calculateMinimumHP(vector<vector<int>>& nums) {
           int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
         return dfs(nums,0,0,dp);
    }
};