class Solution {
public:
    bool isPossible(const string& prefix, const string& target,
                    vector<int> freq, char mid, int n) {
        int len = prefix.length();
        string target_prefix = target.substr(0, len);

        // 1. If prefix already deviates from target, we know the answer
        // immediately
        if (prefix > target_prefix)
            return true;
        if (prefix < target_prefix)
            return false;

        // 2. If it's an exact match so far, build the largest possible
        // remaining left half
        string max_left = prefix;
        for (int i = 25; i >= 0; i--) {
            while (freq[i] > 0) {
                max_left += (char)('a' + i);
                freq[i]--; // Decrement pairs
            }
        }

        // 3. Construct the full simulated max palindrome
        string max_palindrome = max_left;
        if (n % 2 != 0) {
            max_palindrome += mid;
        }

        string right_half = max_left;
        reverse(right_half.begin(), right_half.end());
        max_palindrome += right_half;

        // 4. Check if the best possible palindrome is strictly greater
        return max_palindrome > target;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd_count = 0;
        char mid = 0; // use 0 or null character as default

        // Count frequencies and identify the middle character if the length is
        // odd
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                mid = 'a' + i;
                freq[i]--; // Remove the middle character from the pairs count
            }
            freq[i] /= 2; // Convert to count of available pairs
        }

        // A palindrome can have at most one character with an odd frequency
        if (odd_count > 1)
            return "";

        string prefix = "";

        // Greedily build the first half of the palindrome
        for (int pos = 0; pos < n / 2; pos++) {
            bool placed = false;

            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    prefix += (char)('a' + i);
                    freq[i]--;

                    // Pass all 5 required arguments to isPossible
                    if (isPossible(prefix, target, freq, mid, n)) {
                        placed = true;
                        break; // Valid character found, lock it in and move to
                               // next position
                    }

                    // Backtrack if not possible
                    freq[i]++;
                    prefix.pop_back();
                }
            }

            // If we couldn't place any valid character, no solution exists
            if (!placed) {
                return "";
            }
        }

        // Reconstruct the full palindrome
        string ans = prefix;
        if (n % 2 != 0) {
            ans += mid;
        }

        string right_half = prefix;
        reverse(right_half.begin(), right_half.end());
        ans += right_half;

        // Final safety check
        if (ans > target) {
            return ans;
        }

        return "";
    }
};