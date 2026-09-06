class Solution {
public:

    int f(string & s,string & t,int index, int j,vector<vector<int>>&dp ){
        //base case
        if(j==-1)return 1;
        if(index<0)return 0;
        
      //  if(size<=0)return 0;
    if(dp[index][j]!=-1)return dp[index][j];

   //character lene wala case 
        int op1=0;int op2=0;int op3=0;
        if(s[index]==t[j]) { 
            //take
            op1=f(s,t,index-1,j-1,dp);
            // not take 
            op2=f(s,t,index-1,j,dp);}
            else{
                  op3=f(s,t,index-1,j,dp);
            }
        
        
        
          
        

        //charater not pick wala case
        

       return  dp[index][j]=op1+op2+op3;
        
    }
   
    int numDistinct(string s, string t) {
         int index=s.size()-1;
         int size=t.size();
         vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));

     return f(s,t,index,t.size()-1,dp);

    }
};