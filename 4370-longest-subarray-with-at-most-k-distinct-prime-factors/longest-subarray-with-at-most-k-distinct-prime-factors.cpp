class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int maxi=INT_MIN;
        for(auto i:nums)maxi=max(maxi,i);
        vector<int>spf(maxi+1);
        for(int i=2;i<=maxi;i++)spf[i]=i;

        for(int i=2;i*i<=maxi;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=maxi;j+=i){
                    if(spf[j]==j)spf[j]=i;
                }
            }
        }

        auto getFactors=[&](int n){
            vector<int>factors;
            while(n>1){
                int p=spf[n];
                factors.push_back(p);
                while(n%p==0)n/=p;
            }
            return factors;
        };

        unordered_map<int,int>primecnt;
        int dist=0;
        int ans=0;
        int left=0;

        for(int right=0;right<nums.size();right++){
            for(int p:getFactors(nums[right])){
                if(primecnt[p]==0)dist++;
                primecnt[p]++;
            }
         
             while(dist>k){
                 for(int p:getFactors(nums[left])){
                     primecnt[p]--;
                     if(primecnt[p]==0)dist--;
                 }
                 left++;
             }
             ans=max(ans,right-left+1);
        }
         
     return ans;
    }
};