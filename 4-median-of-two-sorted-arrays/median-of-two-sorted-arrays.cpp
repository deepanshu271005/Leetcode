class Solution {
public:
  
    int f(int idx,vector<int>& nums1, vector<int>& nums2)  {
        int l=-1e6,r=1e6;
        int mid;
        int ans=INT_MAX;
        while(l<=r){
         mid=(l+r)/2;
         //now i have to find the number which is leess than this in  both array 
           
           int i = lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();//<
           int i2 = lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();//<
           int t=i+i2;
           if(idx<=t){
            r=mid-1;
           }
           else {
            ans=mid;
            l=mid+1;
           }

        }
      return ans;  
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int t=nums1.size()+nums2.size();

        int mid=(t+1)/2;
        if(t%2){
            return f(mid,nums1,nums2);
        }
        return (1.0*(f(mid,nums1,nums2)+f(mid+1,nums1,nums2)))/2;
    }
};