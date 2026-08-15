class Solution {
public:
    int hIndex(vector<int>& citations) {
        
       sort(citations.begin(),citations.end());
         int best=0;
         int n=citations.size();
         for(int curr=1;curr<=1000;curr++){
            int cnt=0;
            for(auto i:citations){
                if(i>=curr)cnt++;
            }
           if(cnt>=curr){
            //cout<<curr<<" "<<cnt<<endl;
            best=curr;
           }
         }
         return best;
    }
};