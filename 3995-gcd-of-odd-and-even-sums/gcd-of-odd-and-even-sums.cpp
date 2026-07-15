class Solution {
public:
    int gcdOfOddEvenSums(int n) {
         
         int sumOdd= n*(1+(n-1)*1);
         int sumEven=n*(2+(n-1)*1);
         //sum of AP seires=n/2(2*A+(n-1)D);

         return gcd(sumOdd,sumEven);

    }
};