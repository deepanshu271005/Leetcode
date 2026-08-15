class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        
        int ans=0;
        int n=nums.size();
        int l=0;int r=n-1;
         while(l<=r){
        if(m[nums[l]]>=2){
            swap(nums[l],nums[r]);
            r--;
        }
        else {
            m[nums[l]]++;
            l++;
        }
        ans=max(ans,l);
    }
       sort(nums.begin(),nums.begin()+ans);
       return ans;
 
    }
};