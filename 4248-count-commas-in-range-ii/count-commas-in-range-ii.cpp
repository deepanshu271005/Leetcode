class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long start = 1000;
        long long end = 999999;
        long long commasPerNumber = 1;
        
        while (n >= start) {
            if (n > end) {
                // Completely covers this range (e.g., all 4-6 digit numbers)
                commas += (end - start + 1) * commasPerNumber;
            } else {
                // Partially covers this range (stops at n)
                commas += (n - start + 1) * commasPerNumber;
                break;
            }
            
            // Shift to the next comma bracket (millions, billions, etc.)
            start *= 1000;
            end = end * 1000 + 999;
            commasPerNumber++;
        }
        
        return commas;
    }
};