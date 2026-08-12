class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();
        
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            vector<int> freq(26, 0);
            int i = 0, j = 0;
            int unique = 0, countAtLeastK = 0;
            
            while (j < n) {
                if (freq[s[j] - 'a'] == 0) unique++;
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] == k) countAtLeastK++;
                
                while (unique > uniqueTarget) {
                    if (freq[s[i] - 'a'] == k) countAtLeastK--;
                    freq[s[i] - 'a']--;
                    if (freq[s[i] - 'a'] == 0) unique--;
                    i++;
                }
                
                if (unique == uniqueTarget && unique == countAtLeastK) {
                    ans = max(ans, j - i + 1);
                }
                j++;
            }
        }
        return ans;
    }
};