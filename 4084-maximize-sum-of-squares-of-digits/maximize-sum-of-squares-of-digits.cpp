class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(num){
            if(sum>9){
                ans+=9+'0';
                sum-=9;
            }
            else if(sum>0) {
                ans+=sum+'0';
                sum=0;
            }
            else ans+=sum+'0';
            num--;
        }
        if(sum>0)return "";
        return ans;
    }
};