class Solution {
public:
    // Helper function using KMP algorithm to check if 'pattern' is a subarray of 'text'
    bool isCyclicRotation(const vector<int>& nums, const vector<int>& sorted_nums, int start, int k) {
        // Pattern is the sorted version of the current block
        vector<int> pattern(k);
        for (int i = 0; i < k; ++i) {
            pattern[i] = sorted_nums[start + i];
        }
        
        // Text is the original block concatenated with itself (size 2k - 1 is enough)
        vector<int> text(2 * k - 1);
        for (int i = 0; i < 2 * k - 1; ++i) {
            text[i] = nums[start + (i % k)];
        }

        // KMP Algorithm preprocessing (LPS array)
        vector<int> lps(k, 0);
        for (int i = 1, len = 0; i < k; ) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // KMP Search
        for (int i = 0, j = 0; i < 2 * k - 1; ) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == k) {
                    return true; // Match found, it is a valid rotation
                }
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        // Create the target sorted array
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int sortable_sum = 0;
        
        // Test all possible block sizes k
        for (int k = 1; k <= n; ++k) {
            // k must divide the length of the array
            if (n % k != 0) continue;
            
            bool is_valid_k = true;
            
            // Check every block of size k
            for (int start = 0; start < n; start += k) {
                if (!isCyclicRotation(nums, sorted_nums, start, k)) {
                    is_valid_k = false;
                    break;
                }
            }
            
            // If all blocks can be rotated to match the sorted version, add k to the sum
            if (is_valid_k) {
                sortable_sum += k;
            }
        }
        
        return sortable_sum;
    }
};