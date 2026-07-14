class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto i:nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
            int ans=1;
         for(int i=1;i<=mini;i++){
            if( maxi % i==0 && mini % i==0)ans=i;
         }
         return ans;
     }
};