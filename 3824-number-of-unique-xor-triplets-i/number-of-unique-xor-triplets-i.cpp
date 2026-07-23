class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        //there are n number marked from 1 to n so if i XOR them then is guranteed that i will get all the number from 0 to nearest 2powerX of n 
        //whcih means 2powX>=n;

        if (n <= 2) {
            return n;
        }
        int pow=1;
        while(pow<=n){
            pow=pow<<1;
        }
        return pow;
    }
};
// 1 0 0
// 0 1 1