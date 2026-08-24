class Solution {
public:
    int countDigitOne(int n) {
        // digit  dp question
        // dp[idx][tight][cnt]-> tells what is the number of ways to make the
        // number of length i(prefix idx) with tight and the number of 1 =cnt so
        // at last the total number of 1 is (summation for all cnt =>>
        // cnt*dp[N][0][cnt]+cnt*dp[N][1][cnt])


        string s = to_string(n);
        int len = s.length();
        vector<vector<vector<long long>>> dp(
            len + 1,
            vector<vector<long long>>(2, vector<long long>(len + 1, 0)));
            //base case
        dp[0][1][0] = 1;

       for(int idx=0;idx<len;idx++){
  
         for(int tight=0;tight<=1;tight++){

            for(int cnt=0;cnt<=idx;cnt++){
                  if(dp[idx][tight][cnt]==0)continue;

             
                int limit=tight?(s[idx]-'0'):9;
              
                 for(int d=0;d<=limit;d++){
               
                 bool new_tight=(tight&(d==limit));//new tight
                 int new_cnt=cnt+(d==1);                 
                 
                    dp[idx+1][new_tight][new_cnt]+=dp[idx][tight][cnt];
                 
                 }


            }

         }

       }

        int ans=0;
        for(int i=0;i<=len;i++){
            ans+=i*dp[len][0][i];
            ans+=i*dp[len][1][i];
        }
 
     return ans;
       
    }
};