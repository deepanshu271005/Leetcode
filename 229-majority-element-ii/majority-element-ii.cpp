class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     //  if(nums.size()==1)return {nums[0]};
      // if(nums.size()==2)return {nums[0],nums[1]};
       int p1=0;
       int p2=0;
       int cnt1=0;
       int cnt2=0;
         
      for(int i=0;i<nums.size();i++){
        if(nums[i]==p1){
            cnt1++;
        }
       else if(nums[i]==p2){
            cnt2++;
        }
      
      else  if(cnt1==0){
            cnt1=1;
            p1=nums[i];
        }
      else  if(cnt2==0){
            cnt2=1;
            p2=nums[i];
        }
        else {
            cnt1--;
            cnt2--;
        }

      }

       cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num == p1) cnt1++;
            else if (num == p2) cnt2++;
        }

        vector<int> result;
        if (cnt1 > nums.size() / 3) result.push_back(p1);
        if (cnt2 > nums.size() / 3) result.push_back(p2);

        return result;

    }
};