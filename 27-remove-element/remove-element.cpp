class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=nums.size()-1;
        int i=0;int cnt=0;
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                j--;
            }
            else {
                cnt++;
                i++;
            }
        }

        return cnt;

    }
};