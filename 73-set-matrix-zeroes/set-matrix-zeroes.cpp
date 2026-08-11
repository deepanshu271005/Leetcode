class Solution {
public:
 
   void f(int &x,int &y,vector<vector<int>>&matrix){
     int n=matrix.size();
     int m=matrix[0].size();
    for(int i=0;i<n;i++){
        matrix[i][y]=0;
    }
    for(int i=0;i<m;i++){
        matrix[x][i]=0;
    }
    return ;
   }

    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
         queue<pair<int,int>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)q.push({i,j});
            }
         }

       while(!q.empty()){
         auto [x,y]=q.front();
         q.pop();
         f(x,y,matrix);
       }
    return ;

    }
};