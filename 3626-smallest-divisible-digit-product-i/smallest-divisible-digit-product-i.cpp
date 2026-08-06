class Solution {
public:
    int smallestNumber(int n, int t) {
         
         for(int i=n;true;i++){
            int sum=1;
            int copy=i;
            while(copy){
                sum*=copy%10;
                copy/=10;
            }
            if(sum%t==0)return i;
         }
         return -1;
        
    }
};