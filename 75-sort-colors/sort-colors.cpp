class Solution {
public:
    void sortColors(vector<int>& nums) {
         
     int low=0;
     int mid=0;
     int high=nums.size()-1;

     //if i found 0 swap with low and inc mid 
     //if i found 1 just +1 mid 
     // if i found 2 swap with the high and dont inc the mid 

      while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
             mid++;
        }
        else {
                 swap(nums[high],nums[mid]);
                 high--;
        }
     }
         
         return ;
    }
};