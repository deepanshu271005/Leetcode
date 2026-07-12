class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        int ans=n;
        vector<int>candy(n,1);//given alteast one candy to all 
        for(int i=0;i<n;i++){
             int prev=i-1;
             int next=i+1;
             while(true){
                if(prev>=0 && rating[i]>rating[prev] && candy[i]<=candy[prev]){
                    candy[i]++;
                    ans++;
                }
            else if(next<n && rating[i]>rating[next] && candy[i]<=candy[next]){
                    candy[i]++;
                    ans++;
                }
                else {
                    break;
                }
             }
        }


            for(int i=n-1;i>=0;i--){
             int prev=i+1;
             int next=i-1;
             while(true){
                if(prev<n && rating[i]>rating[prev] && candy[i]<=candy[prev]){
                    candy[i]++;
                    ans++;
                }
            else if(next>=0 && rating[i]>rating[next] && candy[i]<=candy[next]){
                    candy[i]++;
                    ans++;
                }
                else {
                    break;
                }
             }
        }
         
        return ans;
        
    }
};