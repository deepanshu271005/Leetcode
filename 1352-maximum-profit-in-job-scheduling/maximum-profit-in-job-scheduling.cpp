class Solution {
public:
    int jobScheduling(vector<int>& start , vector<int>& end , vector<int>& profit) {
        
        vector<pair<pair<int,int>,int>>a;
        int n=start.size();
        for(int i=0;i<n;i++){
            a.push_back({{end[i],start[i]},profit[i]});
        }
        sort(a.begin(),a.end());
        vector<int>end1;
        for(auto &i:a){
            swap(i.first.first,i.first.second);
            end1.push_back(i.first.second);
        }
        
         
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(2));
        dp[0][0]={0,0};
        dp[0][1]={a[0].second,a[0].first.second};

        for(int i=1;i<n;i++){
            // dont want to do curr job
            int startTimeOfThisJob=a[i].first.first;
            int endTimeOfThisJob=a[i].first.second;
            int profit=a[i].second;
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]={profit,endTimeOfThisJob};

            // do this job and check which last job can be done with this 
            // int maxPrevProfit = 0;
            // for(int j=i-1;j>=0;j--){
            //     if(dp[j][1].second<=startTimeOfThisJob){
            //        maxPrevProfit = max(maxPrevProfit, dp[j][1].first);
            //     }
            // }
            // dp[i][1] = {profit + maxPrevProfit, endTimeOfThisJob};
           //slow code where we find the last suitbale job in o(n) 
              
         auto j=upper_bound(end1.begin(),end1.end(),startTimeOfThisJob);
         if( j==end1.begin())continue;
         //j=j-end1.begin();//this index is striucly > startTimeOfThisJob
          auto it=j-end1.begin()-1;
          int maxPrevProfit = 0;
          maxPrevProfit=max(dp[it][1].first,dp[it][0].first);
           dp[i][1]={maxPrevProfit+profit,endTimeOfThisJob};

        }
        return max(dp[n-1][0].first,dp[n-1][1].first);

    }
};