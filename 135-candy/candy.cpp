class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        int ans=n;
        vector<int>candy(n,1);//given alteast one candy to all 
        for(int i=0;i<n;i++){
             int prev=i-1;
             int next=i+1;
            int new_candy=0;
             if(prev>=0 && rating[i]>rating[prev] && candy[i]<=candy[prev]){
                      new_candy=max(new_candy,candy[prev]);
                     
                }
             if(next<n && rating[i]>rating[next] && candy[i]<=candy[next]){
                     new_candy=max(new_candy,candy[next]);
                }
                
           if(new_candy!=0) {  int more_candies=new_candy-candy[i]+1;
              ans+=more_candies;
              candy[i]=new_candy+1;}
        }


            for(int i=n-1;i>=0;i--){
             int prev=i+1;
             int next=i-1;
              int new_candy=0;
                if(prev<n && rating[i]>rating[prev] && candy[i]<=candy[prev]){
                       new_candy=max(new_candy,candy[prev]);
                }
              if(next>=0 && rating[i]>rating[next] && candy[i]<=candy[next]){
                       new_candy=max(new_candy,candy[next]);
                }
               
               if(new_candy!=0) {  int more_candies=new_candy-candy[i]+1;
              ans+=more_candies;
              candy[i]=new_candy+1;}
             
        }
         
        return ans;
        
    }
};