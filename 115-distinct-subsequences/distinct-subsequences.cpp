class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size(); 
        vector<vector<unsigned int>>dp(n+1,vector<unsigned int>(m+1,0));
        //dp[i][j]->tells the ways that we can make the string upto len i from the other string to the len j 
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1]+=dp[i][j];//this is the ways if we choose to include the current character and check the last i,j 
                    dp[i+1][j+1]+=dp[i][j+1];//if we choose not to take the i+1 char then we check the i,j+1 gives us what 
                }
                else {
                    dp[i+1][j+1]+=dp[i][j+1];//character mismatches is simply take the last i,j+1 ways
                }
            }
        }

        return dp[n][m];
 
    }
};