class Solution {
public:
    bool canAliceWin(int n) {
        int start=10;
        bool ans=false;
        while(n>=start){
            n-=start;
            ans=!ans;
            start--;
        }
        return ans;
    }
};