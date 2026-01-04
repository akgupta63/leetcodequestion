class Solution {
public:
    double memo[205][205];

    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (memo[a][b] >= 0) return memo[a][b];

        return memo[a][b] = 0.25 * (
            dfs(a - 4, b) +
            dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) +
            dfs(a - 1, b - 3)
        );
    }

    double soupServings(int n) {
        // Optimization for large n
        if (n >= 4800) return 1.0;

        int m = (n + 24) / 25; // scale down

        memset(memo, -1, sizeof(memo));
        return dfs(m, m);
    }
};
