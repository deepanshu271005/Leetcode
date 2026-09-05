class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        //dp1->stores the lenght of the longest positive subseq ending on it 
        //dp2->stores the lenght of the longest positive subseq ending on it

        for(int i=1;i<n;i++){
          for(int j=i-1;j>=0;j--){
            int diff=nums[i]-nums[j];
            if(diff==0)continue;//skip if two number are the same
            if(diff>0){
                dp1[i]=max(dp1[i],1+dp2[j]);
            }
            else if(diff<0){
                dp2[i]=max(dp2[i],1+dp1[j]);
            }
          }
        } 
          
 
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,max(dp1[i],dp2[i]));
        }
        // for(auto i :dp1)cout<<i<<" ";
        // cout<<endl;
        // for(auto i :dp2)cout<<i<<" ";   
         return ans;
 
    }
};