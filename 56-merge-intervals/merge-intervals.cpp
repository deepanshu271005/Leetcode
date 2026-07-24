class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>>s;
        sort(intervals.begin(),intervals.end());
        for(auto i:intervals){
            if(s.empty())s.push({i[0],i[1]});
            else{
                auto it=s.top();
                int start=it.first;
                int end=it.second;
                int startOfCurrent=i[0];
                int endOfCurrent=i[1];
                if(startOfCurrent<=end){
                    s.pop();
                    s.push({min(start,startOfCurrent),max(endOfCurrent,end)});
                }
                else s.push({startOfCurrent,endOfCurrent});
            }
        }
     
        vector<vector<int>>ans;
       while(!s.empty()){
        auto it=s.top();
        s.pop();
        ans.push_back({it.first,it.second});
       }

       reverse(ans.begin(),ans.end());
       return ans;

    }
};