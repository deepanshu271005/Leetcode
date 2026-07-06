class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //first let do brute force traver all over for each interval 
        int n=intervals.size();
        int ans=n;
        for(int i=0;i<n;i++){
            int curr_int_start=intervals[i][0];
            int curr_int_end=intervals[i][1];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int next_int_start=intervals[j][0];
                int next_int_end=intervals[j][1];

                //check if the current interval is covered ?
                if(curr_int_start>=next_int_start && curr_int_end<=next_int_end){ans--;break;}
            }
        }
        return ans;
    }
};