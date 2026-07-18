class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         
       int idx1=m;int idx2=0;
       while(idx1<m+n){
           nums1[idx1++]=nums2[idx2++];
       }
       sort(nums1.begin(),nums1.end());
       return;

    }
};