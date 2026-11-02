class Solution {
public:
    int getmask(int n) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mask = 0;
        for (int i = 0; i < primes.size(); i++) {
            if (n % (primes[i] * primes[i]) == 0) {
                return -1;
            } else if (n % primes[i] == 0) {
                mask |= (1 << i);
            }
        }
        return mask;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        // the naive method is simply to create all the subset and check that
        // the PF of them should conatin each prime only one
        // dp[i][mask]-> tell me the number of subsets ending at i having the
        // prime factor as mask 2 3 5 7 11 13 17 19 23 29    10->prime
        int tmask = (1 << 10);
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<vector<long long>> dp(31, vector<long long>(tmask, 0));
        vector<int> freq(31, 0);
        for (auto i : nums) {
            freq[i]++;
        }
        dp[1][0] = 1; // there is 1 subset with no prime number in the start
        for (int x = 2; x <= 30; x++) {
            for (int mask = 0; mask < tmask; mask++)
                dp[x][mask] = dp[x - 1][mask];

            if (freq[x] == 0)
                continue;

            int currmask = getmask(x);

            if (currmask == -1)
                continue;

            for (int mask = 0; mask < tmask; mask++) {

                if ((mask & currmask) == 0) {

                    dp[x][mask | currmask] =
                        (dp[x][mask | currmask] + dp[x - 1][mask] * freq[x]) %
                        MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 1; i < tmask; i++) {
            ans = (ans + dp[30][i]) % MOD;
        }
        int onesfreq = freq[1];

        long long power = 1;

        for (int i = 0; i < onesfreq; i++) {
            power = (power * 2) % MOD;
        }

        return (ans * power) % MOD;
    }
};