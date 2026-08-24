// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         priority_queue<long long,vector<long long >,greater<long long>>pq;
//         pq.push(1);
//         set<int>s;
//         while(s.size()<n){
//             long long i=pq.top();
//             pq.pop();
//             if(s.find(i)!=s.end()){continue;}
//             pq.push(2*i);
//             pq.push(3*i);
//             pq.push(5*i);
//             s.insert(i);
//         }
//         auto it=s.rbegin();
//         return *it;

//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1; 
        
        int p2 = 0, p3 = 0, p5 = 0;
        
        for (int i = 1; i < n; i++) {
            int next2 = dp[p2] * 2;
            int next3 = dp[p3] * 3;
            int next5 = dp[p5] * 5;
            
            int next_ugly = min({next2, next3, next5});
            dp[i] = next_ugly;
            
          
            if (next_ugly == next2) p2++;
            if (next_ugly == next3) p3++;
            if (next_ugly == next5) p5++;
        }
        
        return dp[n - 1];
    }
};