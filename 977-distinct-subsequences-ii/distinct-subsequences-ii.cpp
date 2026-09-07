int MOD=1e9+7;
class Solution {
public:
    int distinctSubseqII(string s) {
        
      int n=s.size();
      vector<vector<int>>dp(n,vector<int>(26,0));
      //dp[i][j]->represent the cnt of distinct subseq that can  made of charcter utpo i index and all the subseq contain the last char j
      //base case 
      dp[0][s[0]-'a']=1;
      int last_sum=1;//this reresent the sum of dp[i-1][all j] so when the charter matches we use this then
      for(int i=1;i<n;i++){
        int curr_sum=0;
         for(int j=0;j<26;j++){
            if(s[i]-'a'==j){
             dp[i][j]=(last_sum+1)%MOD;
             curr_sum=(curr_sum+dp[i][j])%MOD;
            }
            else {
                dp[i][j]=dp[i-1][j];
                curr_sum=(curr_sum+dp[i][j])%MOD;
            }
         }
         last_sum=curr_sum;
      }
    
       int ans=0;
       for(int i=0;i<26;i++)ans=(ans+dp[n-1][i])%MOD;
       return ans;

    }
};