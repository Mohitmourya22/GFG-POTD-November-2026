// Date: 6 Nov 2026
// Problem: Balanced Binary Tree Counter
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBT(int h) {
        if (h == 0 || h == 1) return 1;

        long long mod = 1000000007;
        long long dp0 = 1; // dp[0]
        long long dp1 = 1; // dp[1]
        long long dpi = 0;

        for (int i = 2; i <= h; ++i) {
            // dp[i] = dp[i-1] * (2 * dp[i-2] + dp[i-1])
            dpi = (dp1 * (2 * dp0 + dp1) % mod) % mod;
            dp0 = dp1;
            dp1 = dpi;
        }

        return dpi;
    }
};
