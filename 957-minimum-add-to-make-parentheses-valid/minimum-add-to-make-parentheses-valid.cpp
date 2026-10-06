class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int cnt=0;
        for(auto i:s){
            if(i=='(')cnt++;
            else cnt--;
            if(cnt<0){ans+=abs(cnt);cnt=0;}
        }
        return cnt+ans;
    }
};