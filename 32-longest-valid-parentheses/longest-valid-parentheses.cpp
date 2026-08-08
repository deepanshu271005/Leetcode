class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<char>st;
        // for(auto i:s){
        //     if(i==')' && !st.empty() && st.top()=='('){
        //         st.pop();
        //     }
        //     else {
        //         st.push(i);
        //     }
        // }
        // return s.size()-st.size();
        

      // dp solution 
      //dp[i]-> max length of the substring strictly ending at i;
         int n=s.size();
         int ans=0;
         vector<int>dp(n,0);
         if(n<2){
            return 0;
         }
         if(s[0]=='(' && s[1]==')')dp[1]=2;
         for(int i=2;i<n;i++){
            if(s[i]=='(')continue;
            else{
            
             int cnt=1;
             for(int j=i-1;j>=0;j--){
               // cout<<"aua";
                if(s[j]==')')cnt++;
                else cnt--;
                if(cnt==0){
                    // this is the matching opening bracket of the ith index 
                    if(j==0)dp[i]=i-j+1;
                    else dp[i]=i-j+1+dp[j-1];
                    break;
                }
             }
            }
         }


        for(auto i:dp){ans=max(ans,i);}
           return ans;
    }
};