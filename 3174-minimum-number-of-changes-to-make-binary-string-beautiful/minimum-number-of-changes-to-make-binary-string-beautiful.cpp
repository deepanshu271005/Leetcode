class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int i=0;int j=1;
        while(j<s.size() && i<s.size()){
            if(s[i]!=s[j])ans++;
            i=j+1;
            j=i+1;
        }
        return ans;
    }
};