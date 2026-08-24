class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        
    int n=stones.size();
    vector<int>dp(n+1,0);
    vector<int>prefix(n);
    prefix[0]=stones[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+stones[i];
    }
 //dp[i]->tells that what is the max score diff that i can get if player 1 plays cutting the row fron either i or >i index 
 //base case if we are at extreme last then p1 have nochance of cutting after i+1 so he must cut here and take all the stones left to it that is prefix[i];
  dp[n-1]=prefix[n-1];
  for(int i=n-2;i>=1;i--){
          dp[i]=max(dp[i+1],prefix[i]-dp[i+1]); 
  }
     return dp[1];
    }
};