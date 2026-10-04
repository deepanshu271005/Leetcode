class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0;
        for (auto i : s) {
            if (i == '*' || i == '(')
                cnt++;
            else
                cnt--;
            if (cnt < 0)
                return false;
        }
        cnt = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '*' || s[i] == ')')
                cnt++;
            else
                cnt--;

            if (cnt < 0)
                return false;
        }
        return true;
    }
};