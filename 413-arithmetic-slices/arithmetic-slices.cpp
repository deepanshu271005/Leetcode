class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        
        int total_slices = 0;
        int current_slices = 0;
        
        for (int i = 2; i < nums.size(); i++) {
            // Check if the current 3 elements form an arithmetic sequence
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                current_slices += 1;
                total_slices += current_slices;
            } else {
                // Reset if the sequence breaks
                current_slices = 0;
            }
        }
        
        return total_slices;
    }
};