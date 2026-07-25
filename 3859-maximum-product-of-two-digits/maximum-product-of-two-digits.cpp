class Solution {
public:
    int maxProduct(int n) {
       int first=INT_MIN;
       int second=INT_MIN;
        while(n){
            int last=n%10;
            if(last>first){
                second=first;
                first=last;
            }
            else if(last>second){
                second=last;
            }
            n=n/10;
        }
     return first*second;

    }
};