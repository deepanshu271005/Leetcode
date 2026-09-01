class Solution {
public:
 

    void f(int&n,string&s,vector<string>&ans,int open,int close){
           if(s.size()==2*n && open==close){ans.push_back(s);return;}
           if(s.size()>=n*2)return;

           if(open<n){
            s.push_back('(');
            f(n,s,ans,open+1,close);
            s.pop_back();
           }
           if(open>close){
            //there is a open bracket so i can safely push a close bracket 
            s.push_back(')');
            f(n,s,ans,open,close+1);
            s.pop_back();
           }
           return;

    }
 
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        f(n,s,ans,0,0);
        return ans;
    }
};