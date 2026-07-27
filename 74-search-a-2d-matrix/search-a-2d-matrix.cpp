class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int r=(n*m)-1;
        int mid;
        while(l<=r){
        mid=(l+r)/2;
          int x=mid/m;
          int y=mid%m;
          if(matrix[x][y]==target)return true;
          if(matrix[x][y]>target){
            r=mid-1;
          }
          else {
            l=mid+1;
          }
        }


        return false;

    }
};