class Solution {
public:

    long long power(long long a, long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b%2)
            {
                ans *= a;
            }
            a *= a;
            b/=2;
        }
        return ans;
    }
    int integerBreak(int n) {

        long long a = 1;

        for(int k=2; k<=n; k++)
        {
            long long b1 = n/k;
            long long e1 = k - n%k;
            long long ans = power(b1, e1);
            long long ans2 = power(b1+1, k - e1);

            a = max(ans*ans2, a);

            // cout << k << "  " << ans << " " << ans2 << endl;
        }

        return a;
    }
};