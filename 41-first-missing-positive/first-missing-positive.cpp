class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag = false;
        for (auto i : nums) {
            if (i >= 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            return 1;
      // cout<<"dbg ";
        // i will have a first loop which will collect all the -ve number and
        // append them to the last
        int lastIdx = nums.size() - 1;
        int i=0;
        while (i <= lastIdx) {
            if (nums[i] <= 0) {
                swap(nums[i], nums[lastIdx]);
                lastIdx--;
            } else {
                i++;
            }
        }
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << lastIdx;
        // cout << endl;

        // now we have gathered all the -ve element at the back so now use the
        // cyclic sort to procced further without including the -ve element and
        // the conditon to stop a SWAP is simpe either the number is out of
        // indexig that is the remaining size of the array without the -ve or if
        // we succesgully have the currect number at the currnet index than stop
        // swapping
        //  cout<<"dbg ";
        int newLength =
            lastIdx +
            1; // no numer should be greater than this to be consecutive
        for (int i = 0; i <= lastIdx; i++) {
            while (nums[i] - 1 != i && nums[i] <= newLength) {
                   if(nums[i]==nums[nums[i]-1])break;//infinite swap
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // for (auto i : nums) {
        //     cout << i << " ";
        // }
          // cout<<"dbg ";
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=ans){
                return ans;
            }
            ans++;
        }
      //   cout<<"dbg ";
        return ans;
    }
};
// cout<<"dbg ";