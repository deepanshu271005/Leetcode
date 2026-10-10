class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        
        // Combine k1 and k2 since modifying either array has the same effect on the absolute difference
        long long k = (long long)k1 + k2; 
        
        // Since the maximum value in nums1 and nums2 is 10^5, the max difference is also 10^5.
        // We use an array to count the frequency of each difference.
        vector<long long> count(100001, 0);
        long long sumDiff = 0;
        
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            sumDiff += diff;
        }
        
        // If our total modifications (k) can reduce all differences to 0
        if (k >= sumDiff) return 0;
        
        // Greedily reduce the largest differences first
        for (int i = 100000; i > 0 && k > 0; i--) {
            if (count[i] > 0) {
                // If we have enough k to reduce ALL instances of the current maximum difference
                if (k >= count[i]) {
                    count[i - 1] += count[i]; // Move them to the next lower difference
                    k -= count[i];
                    count[i] = 0;
                } 
                // If k runs out before we can reduce all instances of this difference
                else {
                    count[i - 1] += k; // Reduce exactly 'k' instances
                    count[i] -= k;
                    k = 0;
                }
            }
        }
        
        // Calculate the final sum of squared differences
        long long ans = 0;
        for (long long i = 1; i <= 100000; i++) {
            if (count[i] > 0) {
                ans += count[i] * i * i;
            }
        }
        
        return ans;
    }
};