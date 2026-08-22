class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int mul=1;
        int dup=n;
        while(dup){
            int last=dup%10;
            dup/=10;
            sum+=last;
            mul*=last;
        }
       // cout<<sum<<" "<<mul<<endl;
        if(n%(sum+mul)==0)return true;
        return false;
    }
};