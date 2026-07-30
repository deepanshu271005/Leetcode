class Solution {
public:
 
       bool f(vector<int>&piles,int&h, int&k){
        long long time=0;
         for(int i=0;i<piles.size();i++){
            if(piles[i]>k){
                time+=(piles[i]/k);
                if(piles[i]%k)time++;
            }
            else {
                time+=1;
            }
         }
         if(time>h)return false;
         return true;
       }
   
    int minEatingSpeed(vector<int>& piles, int h) {
        //so this is the question from the BS on answer
        // i have to find the min speed at which all banana can be eaten 
        //so suppose i have a value of k and then i can check that can i eat all the banana int he given time or not 

        int l=1;int r=1e9;
        int mid;
        int ans=INT_MAX;
        while(l<=r){
          mid=l+(r-l)/2;
          if(f(piles,h,mid)){
            // this means that the ans is possible 
            ans=min(ans,mid);
            r=mid-1;
          }
          else {
            l=mid+1;
          }
        }
         return ans;
    }
};