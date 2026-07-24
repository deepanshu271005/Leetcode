class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        // Pass 1: Cyclic Sort (Place numbers in nums[i] - 1)
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Pass 2: Find misplaces (duplicates)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};