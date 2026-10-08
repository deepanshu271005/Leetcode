class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<bool>mark(s.size(),true);
        int cnt=0;
        int idx=0;
        for(auto i:s){
            if(cnt==0)mark[idx]=false;
            if(i=='(')cnt++;
            else cnt--;
            if(cnt==0)mark[idx]=false;
            idx++;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(mark[i])ans+=s[i];
        }
        return ans;
    }
};