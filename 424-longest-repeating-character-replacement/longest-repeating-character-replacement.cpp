class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freqcount(200, 0);
        int maxi = 0;
        int left = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            freqcount[(int)s[i]]++;
            maxi = max(maxi, freqcount[(int)s[i]]);
            while (i - left + 1 - maxi > k) {
                freqcount[(int)s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};