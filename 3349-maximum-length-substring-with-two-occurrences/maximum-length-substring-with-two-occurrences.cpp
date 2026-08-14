class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();int ans=0;
       
        int l=0;
        int r=0;
        vector<int>freq(26,0);
        while(r<n && l<=r){
             freq[s[r]-'a']++;
             while(freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
             }
             ans=max(ans,r-l+1);
             r++;
        }
        return ans;

    }
};