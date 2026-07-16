class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // easiest is if i sort this and then compare all the adjacent element
        //  sort(nums.begin(),nums.end());
        //  for(int i=1;i<nums.size();i++){
        //      if(nums[i]==nums[i-1])return nums[i];
        //  }
        //  return -1;

        // how to do this in O(n) tc and O(1)sc
        int fast = 0;
        int slow = 0;

        while (true) {

            slow = nums[slow];
            fast = nums[nums[fast]];

            if (fast == slow) {
                slow = 0;

                while (fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return fast;
            }
        }
        return -1;
    }
};