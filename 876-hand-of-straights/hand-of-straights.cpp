class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if(hand.size()%groupSize!=0)return false;
         
         sort(hand.begin(),hand.end());
         int n=hand.size();
         map<int,int>freq;
         for(auto i:hand){
            freq[i]++;
         }
         //now we have the freq for all 
         for(int i=0;i<n;i++){
            //check if that element has not been used up 
            if(freq[hand[i]]!=0){
               //now we need the consecutive element of grpSize
               int cnt=groupSize;
               int curr_required=hand[i];
               while(cnt){
                if(freq[curr_required]==0)return false;
                   freq[curr_required]--;
                   cnt--;curr_required++;
               }

            }
         }


         return true;
    }
};