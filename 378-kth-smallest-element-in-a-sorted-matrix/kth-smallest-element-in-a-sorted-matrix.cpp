class Solution {
public:
    
     int f(vector<vector<int>>& matrix,int t){
        int n=matrix.size();
        int i=n-1;int cnt=0;
        for(int j=0;j<n;j++){
            
            while(matrix[i][j]>t){
                i--;
                if(i<0)return cnt;
            }
            cnt+=i+1;
        }
        return cnt;
     }

    int kthSmallest(vector<vector<int>>& a, int k) {
        long long l=a[0][0];
        long long h=1e9;
        long long m;
        long long ans;
        while(l<=h){
            m=l+(h-l)/2;
            
            long long lessE=f(a,m);
            if(lessE>k-1){
                 ans=m;
                 h=m-1;
            }
            else {
                l=m+1;
            }

        }
        return ans;

    }
};