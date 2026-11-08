class Solution {
public:



    int countServers(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                 //check the row 
                bool flag=true;
                 for(int k=0;k<m;k++){
                    if(k==j)continue;
                    if(grid[i][k]==1){
                        ans++;
                        flag=false;
                        break;
                    }
                 }
                 //check the col
                 if(flag){
                     for(int k=0;k<n;k++){
                    if(k==i)continue;
                    if(grid[k][j]==1){
                        ans++;
                        break;
                    }
                 }
                 }
            }
        }
       return ans;

    }
};