class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        int sum=0;
        for(auto i:reward2)sum+=i;
        //now we need to replace the k element from this such that the chamnge in sum is optimal 
        //for ever swap change = -reward2[i]+reward1[i];// we need to choose such that this is max so pusuh this in pq 
        priority_queue<int>q;
        for(int i=0;i<n;i++){
            q.push(reward1[i]-reward2[i]);
        }
        while(k--){
            sum+=q.top();
            q.pop();
        }
        return sum;

    }
};