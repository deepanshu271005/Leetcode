class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // so for nums[i]-i != nums[j]-j if we are at index i we know the
        // nums[i]so now we acutly just need the count of all the inde whoose
        // nums[j]-j i not eqaul to nums[i]-i so for each index i could precalc
        // this whcih will save my tc
        unordered_map<int, int> m;
        long long badPairs = 0;

        for (int j = 0; j < nums.size(); j++) {
            int diff = nums[j] - j;

            // Total previous elements (which is j) minus the ones that form
            // good pairs
            badPairs += j - m[diff]; // The total pairs can be 'j' so we sub bad
                                     // pair from it

            // Add current diff to the map for future indices to use
            m[diff]++;
        }

        return badPairs;
    }
};