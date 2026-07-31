class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //the value of x2 and y2 is already fixed that is {0,0};
        //so the question boils down to finding min xsq+ysq;
        //so i need the top k points whose xsq+ysq is min;
        priority_queue<pair<long long,int>>q;//then min k element will be stored 
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            long long dis=x*x+y*y;
            int idx=i;
            q.push({dis,idx});
            while(q.size()>k){
                q.pop();
            }
        }

        vector<vector<int>>ans;
        while(!q.empty()){
            int idx=q.top().second;
            q.pop();
            int x=points[idx][0];
            int y=points[idx][1];
            ans.push_back({x,y});
        }
        return ans;

    }
};