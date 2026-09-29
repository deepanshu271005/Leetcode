class Solution {
public:
     int dx[2]={0,1};
     int dy[2]={1,0};
    bool dfs(vector<vector<int>>&mat,int x,int y,int currSum,vector<vector<vector<bool>>>&dp){
       // cout<<x<<" "<<y<<" "<<currSum<<endl;
        int n=mat.size();
        int m=mat[0].size();
        if(x==n-1 && y==m-1){
            if(currSum==0)return true;
            else return false;
        }
        if(currSum<0)return false;//  if the currSum is negatve then this means that there is a closing bracket without the opning bracker 
        if(dp[x][y][currSum]==false)return false;
       bool ans=false;
        for(int i=0;i<2;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                int newSum=currSum+mat[nx][ny];
                 ans|=dfs(mat,nx,ny,newSum,dp);
            }
            if(ans)return dp[x][y][currSum] =ans;
        }
        return dp[x][y][currSum]=ans;

    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=(grid[i][j]=='(')?1:-1;
            }
        }

     //now i can just call for the dfs where the sum of the path should never be negative and also the total sum at n-1,m-1 should be 0 
  
     
    //  for(auto i:mat){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    //  }
    vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(m,vector<bool>(201,true)));
      
    return dfs(mat,0,0,mat[0][0],dp);

    }
};