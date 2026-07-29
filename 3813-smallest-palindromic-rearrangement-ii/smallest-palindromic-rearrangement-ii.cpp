class Solution {
public:
   
//    int getFactorial(int n){
//     int ans=1;
//     while(n){
//         ans*=n--;
//     }
//     return ans;
//    }

// Safely calculates combinations without intermediate spikes
long long nCrBounded(int n, int r, long long k) {
    if (r > n - r) r = n - r; // This single line prevents the spike!
    
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = (res * (n - i + 1)) / i;
        
        if (res > k) return k + 1; 
    }
    return res;
}

long long calcPermutations(const vector<int>& freq, int total_len, long long k) {
    long long ways = 1;
    int n = total_len; 
    
    for (int f : freq) {
        if (f == 0) continue;
        
        long long combs = nCrBounded(n, f, k);
        
        // Safely multiply the combinations together, checking for overflow
        if (combs >= k + 1 || (k + 1) / ways < combs) {
            return k + 1;
        }
        
        ways *= combs;
        n -= f; // Decrease available positions
    }
    return ways;
}

    string smallestPalindrome(string s, int k) {
        
        if(s.size()==1)return s;

        vector<int>freq(26);
         int n=0;
        for(auto i:s){
            freq[i-'a']++;
              
        }
        char oddCharacter='0';
       for(int i=0;i<freq.size();i++){
        if(freq[i]%2){
            oddCharacter=i+'a';
        }
            freq[i]/=2;
            n+=freq[i];
         }
         // Add this check before trying to build the string
long long total_perms = calcPermutations(freq, n, k);
if (total_perms < k) {
    return ""; // k is larger than the total possible palindromes
}
         int n2=n;bool f=0;
         string ans;
         for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                if(freq[j]==0)continue;
                //fixing
                freq[j]--;
                long long p=calcPermutations(freq,n-i-1,k);
                if(p<k){
                    //ans does not exisst here 
                    k-=p;
                    freq[j]++;
                }
                else {
                    
                    ans.push_back(j+'a');
                    f=1;
                    break;
                }

            }
         }
        string rv = ans;
        reverse(rv.begin(),rv.end());
         if(f==0)return ans;
        return  oddCharacter=='0' ?  ans+rv:ans+oddCharacter+rv; 
    }
};
