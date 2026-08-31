class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size=primes.size();
        
         vector<int>pointer(size,0);
         vector<long long>ans;
         ans.push_back(1);//smalles ugly number
         while(ans.size()<n){
              long long  mini=INT_MAX;
            for(int i=0;i<size;i++){
                mini=min(mini,(long long)primes[i]*(long long)ans[pointer[i]]);
            }
            for(int i=0;i<size;i++){
                if(primes[i]*ans[pointer[i]]==mini){
                    pointer[i]++;
                }
            }
            ans.push_back(mini);
         }
         
         return ans[n-1];
    }
};