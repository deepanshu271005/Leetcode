class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n=matrix.size();
            int m=matrix[0].size();
            for(int i=0;i<n;i++){
                int l=matrix[i][0];
                int h=matrix[i][m-1];
                if(target>=l && target<=h){
        auto it1=lower_bound(matrix[i].begin(),matrix[i].end(),target);
        auto it2=upper_bound(matrix[i].begin(),matrix[i].end(),target);
        if(it1!=it2)return true;
                }
            } 

            return false;

    }
};