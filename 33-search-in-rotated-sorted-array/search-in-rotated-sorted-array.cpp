class Solution {
public:
    int search(vector<int>& nums, int target) {
        //if we split the array in 2 portion one portion is gurateed to be sorted  
        int l=0,h=nums.size()-1;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(target==nums[mid])return mid;
            // the mid element could either lie in the true sorted or in the disrupted so checking it with the low will tell me 
            if(nums[mid]>=nums[l]){
                //this means the low ot mid is sorted 
                if(target>=nums[l] && target<nums[mid]){
                    h=mid-1;
                }
                else {
                    l=mid+1;
                }
            }
            else {
                // the mid to high is sorted for sure;
                if(target>nums[mid] && target<=nums[h]){
                    l=mid+1;
                }
                else h=mid-1;

            }
        }
               return -1;//fallback
    }
};