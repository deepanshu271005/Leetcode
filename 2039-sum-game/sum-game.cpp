class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int sum1=0,sum2=0,cnt1=0,cnt2=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                cnt1++;
                continue;
            }
            else sum1+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?'){
                cnt2++;
                continue;
            }
            else sum2+=(num[i]-'0');
        }
   
          int netQ=0;
         if(cnt1>cnt2){
         netQ=cnt1-cnt2;
         //now both the player will play in left half 
          
            int still_left=sum2-sum1;
            int chanceForBob=netQ/2;
            int bobCanMake=9*chanceForBob;
            int aliceCanMake=9*(netQ-chanceForBob);
            if(still_left>0 && still_left>=aliceCanMake && still_left<=bobCanMake){
                return false;
            }
            return true;

         }
         else if(cnt1<cnt2){
            netQ=cnt2-cnt1;
        //now both the player will play in right half
           
            
            int still_left=sum1-sum2;
            int chanceForBob=netQ/2;
            int bobCanMake=9*chanceForBob;
            int aliceCanMake=9*(netQ-chanceForBob);
            if(still_left>0 && still_left>=aliceCanMake && still_left<=bobCanMake){
                return false;
            }
            return true;

         }
       
         return !(sum1==sum2);

    }
};