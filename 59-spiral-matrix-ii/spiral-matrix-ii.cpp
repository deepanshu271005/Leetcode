class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
           
        int m=n;
        int cnt=1;
         vector<vector<int>>ans(n,vector<int>(n));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<" ("<<i<<","<<j<<") ";
        //     }
        //     cout<<endl;
        // } 
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
       
        while(top<=bottom && left <=right){
           //cout<<1;
            for(int i=left;i<=right;i++){
                 ans[top][i]=cnt++;//upper most row done
            }
            top++;
            if(top>bottom)break;
            for(int i=top;i<=bottom;i++){
                ans[i][right]=cnt++;
            }
            right--;
            if(right<left)break;
            for(int i=right;i>=left;i--){
                ans[bottom][i]=cnt++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                ans [i][left]=cnt++;
            }
            left++;
        }
        

        return ans;
    }
};