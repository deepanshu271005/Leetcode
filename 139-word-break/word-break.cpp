class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int n=s.size();
      vector<bool>dp(n+1,false);
      dp[0]=true;
      unordered_map<string,int>m;
      for(auto i:wordDict){
        reverse(i.begin(),i.end());
        m[i]++;
      }
      //dp[i]->tell is that possible to segment the string s from 0 to i and each segment present in the dic
      for(int i=1;i<=n;i++){
        string temp="";
        temp+=s[i-1];
         if(dp[i-1] && m[temp]){dp[i]=true;continue;}
            for(int j=i-2;j>=0;j--){
                 temp+=s[j];
                // if(i==8)cout<<temp<<endl;
                if(dp[j] && m[temp]){
                    dp[i]=true;
                    break;
                }
                
         }
      }   
   //   for(auto i:dp)cout<<i<<" "; 

      return dp[n];
     
    }
};