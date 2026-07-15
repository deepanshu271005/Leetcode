class Solution {
public:
    int gcdOfOddEvenSums(int n) {
         
         int sumOdd= n*(1+(n-1)*1);
         int sumEven=n*(2+(n-1)*1);

         return gcd(sumOdd,sumEven);

    }
};