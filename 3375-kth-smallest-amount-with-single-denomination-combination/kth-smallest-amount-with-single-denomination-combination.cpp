class Solution {
public:

     long long LCM(long long a,long long b){
        return (a*b)/gcd(a,b);
     } 
      

       bool f(long long m,vector<int>&coins,int k){
       
         long long total=0;
        //  for(int i=0;i<coins.size();i++){
        //      total+=m/coins[i];
        //  }  
         long long tmask=1<<(coins.size());
         // i will add the subset with even set bit in the total and sub the odd set bit subset from total;
       
          for(int mask=1;mask<tmask;mask++){

            long long lcm=1;
            int cnt=0;
            for(int i=0;i<coins.size();i++){
                if((1<<i)&mask){
                    lcm=LCM(coins[i],lcm);
                    cnt++;
                }
            }
            if(cnt%2){
                total+=m/lcm;
            }
            else {
                total-=m/lcm;
            }


          }

            return total>=k;
       }
 
    long long findKthSmallest(vector<int>& coins, int k) {
       //apply binary search on ans;
       long long l=0,r=1e18;
       long long ans=0;
       
        while(l<=r){
             long long m=l+(r-l)/2;

              if(f(m,coins,k)){
                ans=m;
                r=m-1;
              }
              else{
                l=m+1;
              }
       
        }
       
      return ans;

    }
};