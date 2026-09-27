class Solution {
public:
      
     string f(string&s,int &idx,string &curr){
      
      while(idx<s.size())
   {
      if(s[idx]=='('){
         string temp="";
         idx++;
         curr+=f(s,idx,temp);
      }

      else if(s[idx]==')'){
          reverse(curr.begin(),curr.end());
          break;
      }

      else {
       curr+=s[idx];
      }
      idx++;
}
  
  return curr;

     }
   
    string reverseParentheses(string s) {
         string temp="";
         int idx=0;
        return f(s,idx,temp);
    }
};







// class Solution {
// public:

//      string f(string&s,int & idx,string &curr){
//        int n=s.size();
//        if(idx==n)return "";
//        for(idx;idx<n;idx++)
//      {  if(s[idx]=='('){
//         string temp="";
//         curr+=f(s,++idx,temp);
//        }
//        else if(s[idx]==')'){
//         reverse(curr.begin(),curr.end());
//         break;
//        }
//        else curr+=s[idx];}

//          return curr;

//      }
   
//     string reverseParentheses(string s) {
//         string temp="";
//         return f(s,0,temp);
//     }
// };