class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx=0;
        int max_idx=0;
        int n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[min_idx]){
                min_idx=i;
            }
            else if(nums[i]>nums[max_idx]){
                max_idx=i;
            }
            else {
                continue;
            }
        }
          
         // cout<<min_idx<<" "<<max_idx;
          int first_del=min(min_idx,max_idx);
          int sec_del=max(min_idx,max_idx);
          int t_op=min(first_del+1+min(n-sec_del,sec_del-first_del),n-sec_del+min(first_del+1,sec_del-first_del));
          return t_op;

    }
};