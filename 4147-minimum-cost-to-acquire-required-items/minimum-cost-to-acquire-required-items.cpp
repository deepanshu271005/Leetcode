class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long n1 = need1, n2 = need2;
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        
        long long min_need = min(n1, n2);
        long long max_need = max(n1, n2);

        // Option 1: Buy everything individually
        long long opt1 = n1 * c1 + n2 * c2;

        // Option 2: Buy min(need1, need2) using costBoth, remainder individually
        long long opt2 = min_need * cb + (n1 - min_need) * c1 + (n2 - min_need) * c2;

        // Option 3: Buy max(need1, need2) entirely using costBoth
        long long opt3 = max_need * cb;

        return min({opt1, opt2, opt3});
    }
};