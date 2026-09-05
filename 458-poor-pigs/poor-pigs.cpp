class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
    //   int pigs=0;
    //   while(buckets>1){
    //     pigs++;
    //     buckets/=2;
    //   }
    //   return pigs;   
    // this would have been the solution if the minutes to tese is not a factor or minumtes to die 
    int factor=minutesToTest/minutesToDie;
    buckets--;//if none die bucket is removed 
    int pigs=0;
    while(buckets){
        pigs++;
        buckets/=factor+1;
    }
    return pigs;


      

    }
};