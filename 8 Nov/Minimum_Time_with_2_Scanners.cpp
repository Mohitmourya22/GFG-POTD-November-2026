// Date: 8 Nov 2026
// Problem: Minimum Time with 2 Scanners
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, int s1, int s2) {
        long long low = 0;
        long long high = (long long)min(s1, s2) * n;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Number of documents scanned by scanner 1 and scanner 2 in 'mid' time
            long long docs1 = mid / s1;
            long long docs2 = mid / s2;

            if (docs1 + docs2 >= n) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid time
            } else {
                low = mid + 1; // Time is too small, need more time
            }
        }

        return ans;
    }
};
