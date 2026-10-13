class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<long long>pq;
        for(auto i:nums){
            pq.push(1LL*i*i);
        }
        long long ans=0;
        int positive_half=(nums.size()%2==0)?nums.size()/2:(nums.size()/2)+1;//ceil 
        while(positive_half--){
            ans+=pq.top();
            pq.pop();
        }
        while(!pq.empty()){
            ans-=pq.top();
            pq.pop();
        }
        return ans;
    }
};