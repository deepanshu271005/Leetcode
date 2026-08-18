class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }
        
        vector<int> freq(51, 0);
        for(auto i : nums) {
            freq[i]++;
        }
        
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (freq[i] == 1) return i;
            }
            return -1;
        }
     
        int ans = -1;
        int first = nums[0];
        int last = nums[n - 1];
        
        if (freq[first] == 1) ans = max(ans, first);
        if (freq[last] == 1) ans = max(ans, last);
        
        return ans;
    }
};