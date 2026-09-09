class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long step = 1000;
        
        while (n >= step) {
            commas += (n - step + 1);
            step *= 1000;
        }
        
        return commas;
    }
};