class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefixGCD;
        int curr=0;
        for(auto i:nums){
            curr=max(curr,i);
            prefixGCD.push_back(gcd(i,curr));
        }
        int l=0;int r=prefixGCD.size()-1;
        long long ans=0;
        sort(prefixGCD.begin(),prefixGCD.end());
        while(l<r){
            ans+=gcd(prefixGCD[l],prefixGCD[r]);
            l++;r--;
        }
        return ans;

    }
};