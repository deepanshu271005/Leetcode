class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
         int ans=0;
         int cnt=0;
         bool found=false;
         for(auto i:nums){
             ans=ans^i;
             if(i>0)found=true;
         }
         if(ans!=0)return nums.size();
         if(ans==0 && found)return nums.size()-1;
         return 0;

    } 
};