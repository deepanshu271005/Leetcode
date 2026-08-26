class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        string ans = "";

        int l = 0, r = 0;
        int ones = 0;
        while (r < s.size() && l <= r) {
            if (s[r] == '1')
                ones++;

            while (ones > k) {
                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }

            if (ones == k) {
                while (s[l] != '1') {
                    if (s[l] == '1') {
                        ones--;
                    }
                    l++;
                }
                if (ans == "" || ans.size()>r-l+1)
                    ans = s.substr(l, r - l + 1);
                else if(ans.size()==r-l+1)
                    ans = min(ans, s.substr(l, r - l + 1));
            }

            r++;
        }

        return ans;
    }
};