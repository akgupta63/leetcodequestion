class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;

        long long a = 6, b = 6; // row 1

        for (int i = 2; i <= n; i++) {
            long long na = (2*a + 2*b) % MOD;
            long long nb = (2*a + 3*b) % MOD;
            a = na;
            b = nb;
        }

        return (a + b) % MOD;
    }
};
