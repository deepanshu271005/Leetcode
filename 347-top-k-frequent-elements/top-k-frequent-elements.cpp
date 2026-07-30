class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
   map<int,int>m;
   for(auto i:nums){
    m[i]++;
       }
       priority_queue<pair<int,int>>q;
       for(auto i:m){
        int n=i.first;
        int cnt=i.second;
        q.push({cnt,n});
       }
      vector<int>ans;
      while(k--){
        ans.push_back(q.top().second);
        q.pop();
      }
      return ans;

    }
};