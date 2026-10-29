class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
    //dropping all the prev idea this could be like binary lifting 
    // like i should know that for each character at 't' transformation what will be length 
    //so it could be dp also 
    //dp[i][j]->if we have caracter i and j transforamation then what is the length 
    //dp[i][j]=dp[i-1][j-1] 
    //if i==26 dp[i-1][j-1]+1
        int MOD=1e9+7;
        vector<vector<int>>dp(26,vector<int>(t+1,0));
        for(int i=0;i<26;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=t;i++){
            for(int j=0;j<26;j++){
                if(j==25){
                    dp[j][i]=(dp[0][i-1]+dp[1][i-1])%MOD;
                }       
                else dp[j][i]=dp[j+1][i-1];              
            }
        }

        long long ans=0;
        for(auto i:s){
            ans=(ans+dp[i-'a'][t])%MOD;
        }
        return ans;
        

    }
};