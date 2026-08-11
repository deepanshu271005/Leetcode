class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
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
        vector<int>ans;
        while(top<=bottom && left <=right){
           //cout<<1;
            for(int i=left;i<=right;i++){
                 ans.push_back(matrix[top][i]);//upper most row done
            }
            top++;
            if(top>bottom)break;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(right<left)break;
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        

        return ans;
    }
};