class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Create a sorted copy to identify groups
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int current_group = 0;
        unordered_map<int, int> num_to_group;
        unordered_map<int, queue<int>> group_to_elements;

        // Initialize the first element
        num_to_group[sorted_nums[0]] = current_group;
        group_to_elements[current_group].push(sorted_nums[0]);

        // Step 2: Assign elements to groups based on the limit
        for (int i = 1; i < n; ++i) {
            if (sorted_nums[i] - sorted_nums[i - 1] > limit) {
                current_group++;
            }
            num_to_group[sorted_nums[i]] = current_group;
            group_to_elements[current_group].push(sorted_nums[i]);
        }

        // Step 3: Reconstruct the array
        vector<int> result;
        for (int num : nums) {
            int group = num_to_group[num];
            // Take the smallest available element from this number's group
            result.push_back(group_to_elements[group].front());
            group_to_elements[group].pop();
        }

        return result;
    }
};