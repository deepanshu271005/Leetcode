class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
    sort(nums.begin(),nums.end());    
    map<int,bool>visited;
    int ans=-1;
    int idx=0;
    while(idx<nums.size()){
        int last=nums[idx];
          if(!visited[last]){
            visited[last]=1;
            int curr=1;
            while(true){
                if(last>1e3)break;
               int next=last*last;
               auto it=lower_bound(nums.begin(),nums.end(),next);
               if(it!=nums.end() && *it==next){
                   curr++;
                   last=next;
               } 
               else break;
            }
            if(curr>1)ans=max(ans,curr);
          }
     

        idx++;
    }
    return ans;

    }
};