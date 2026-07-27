class Solution {
public:
    int findMin(vector<int>& nums) {
        //same logic if we split the rotated array in 2 parts then one of tha half is guranteed to be sorted 
        int l =0,r=nums.size()-1;
        int mid;
        int ans=INT_MAX;

        while(l<=r){
            mid=(l+r)/2;
          //  ans=min(ans,nums[mid])
            if(nums[mid]>=nums[l]){
                // the part from l to mid is sorted 
                     ans=min(ans,nums[l]);
                     l=mid+1;

            }
            else {
                // mid to r is sorted 
                   ans=min(ans,nums[mid]);
                   r=mid-1;

                }

        }
        return ans;

    }
};