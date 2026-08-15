class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        int r=n-1;
        int l=0 ;
        while(l<=r){
            if(m.find(nums[l])==m.end()){
                m[nums[l]]++;
                l++;
            }
            else {
                 swap(nums[l],nums[r]);
                 r--;
            }
        }
        sort(nums.begin(),nums.begin()+m.size());
         return m.size();

    }
};