class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long >,greater<long long>>pq;
        pq.push(1);
        set<int>s;
        while(s.size()<n){
            long long i=pq.top();
            pq.pop();
            if(s.find(i)!=s.end()){continue;}
            pq.push(2*i);
            pq.push(3*i);
            pq.push(5*i);
            s.insert(i);
        }
        auto it=s.rbegin();
        return *it;

    }
};