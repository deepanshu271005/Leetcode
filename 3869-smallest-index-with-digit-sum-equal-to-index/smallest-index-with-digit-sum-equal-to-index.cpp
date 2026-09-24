class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int idx=i;
            int num=nums[i];
            int sum=0;
            while(num){
                sum+=num%10;
                num=num/10; 
            }
            if(idx==sum)return idx;
        }
        return -1;
    }
};