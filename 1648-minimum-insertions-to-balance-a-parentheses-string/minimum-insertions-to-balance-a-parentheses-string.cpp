class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')open++;
            else {
                if(s[i+1]==')'){
                    i++;
                }
                else ans++;
                open--;
            }
            if(open<0){
                ans+=abs(open);
                open=0;
            }
             
        }
        return ans+2*open;
    }
};