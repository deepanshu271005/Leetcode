class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        vector<int>suffix(n+1,0);
        
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }

      for (int i = 0; i < n; i++) {
    suffix[i + 1] = suffix[i] + nums[n - 1 - i];
}
         
        int ans=INT_MAX;
        // for(auto i:prefix)cout<<i<<" ";
        // cout<<endl;
        // for(auto i:suffix)cout<<i<<" ";
        // cout<<endl;

        for(int i=0;i<=n;i++){
               int left=x-prefix[i];
               if (left < 0) continue;
               auto it=lower_bound(suffix.begin(),suffix.end(),left);
               if(it==suffix.end() || *it!=left)continue;
               int remove_last=it-suffix.begin();
               if(remove_last+i>n)continue;
               ans=min(ans,i+remove_last);

        }

        return (ans==INT_MAX)?-1:ans;

    }
};