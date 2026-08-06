class Solution {
public:


  void makeadj(vector<vector<int>>&times,vector<vector<pair<int,int>>>&adj){
    for(auto i:times){
        adj[i[0]].push_back({i[1],i[2]});
        // node form , to , time taken
    }
    return;
  }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         
      vector<int>time_taken(n+1,INT_MAX);
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      q.push({0,k});
      time_taken[k]=0;
      vector<vector<pair<int,int>>>adj(n+1);
      makeadj(times,adj);
      while(!q.empty()){
       pair<int,int> front=q.top();
       q.pop();
        int time=front.first;
        int node=front.second;
           if(time_taken[node]<time)continue;
        for(auto [neighbour,time_till_neighbour]:adj[node]){
            int ntime = time+time_till_neighbour;
            if(ntime<time_taken[neighbour]){
                time_taken[neighbour]=ntime;
                q.push({ntime,neighbour});
            }
        }
      }
      int ans=INT_MIN;
      
      for(int i=1;i<n+1;i++){
        if(time_taken[i]==INT_MAX)return -1;
        else{
            ans=max(ans,time_taken[i]);
        }
      }
return ans;
    }
};

 