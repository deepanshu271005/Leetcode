class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1];  
    }
    return a[0] < b[0];      
});
        int ans=0;
        int last_end_till_now=-1;
        //if the lastendtillnow is going to update then that interval is unique 
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][1]>last_end_till_now){
                ans++;
                last_end_till_now=intervals[i][1];
            }
        }

        return ans;
    }
};