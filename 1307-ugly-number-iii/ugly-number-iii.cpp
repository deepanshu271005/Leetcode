class Solution {
public:
 
       long long LCM(long long a,long long b) {
        return (a*b)/gcd(a,b);
       }

    int nthUglyNumber(int n, int a, int b, int c) {
        
         long long ab=LCM(a,b);
         long long bc=LCM(c,b);
         long long ca=LCM(a,c);
         long long abc=LCM(a,bc);

           long long l=0,r=2e9;
           while(l<r){
            long long mid=l+(r-l)/2;
           
             int lessThanMid=mid/a+mid/b+mid/c-mid/ab -mid/bc-mid/ca+mid/abc;
              
               if(lessThanMid>=n){
                r=mid;
             }
             else l=mid+1;

           }  
           return l;
 
    }
};