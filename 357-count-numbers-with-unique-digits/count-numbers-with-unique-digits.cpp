class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
       vector<int>dp(n+1,0);
       dp[0]=1;
       dp[1]=9;
       for(int i=2;i<=n;i++){
             dp[i]=dp[i-1]*(11-i);
       }
   
   int ans=0;
   for(auto i:dp)ans+=i;
   return ans;

      
       
    }
};