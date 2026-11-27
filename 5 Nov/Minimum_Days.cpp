// Date: 5 Nov 2026
// Problem: Minimum Days
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinimumDays(string &s, vector<int> &p) {
        int n = s.length();

        // Map each index to the day it gets replaced.
        // Since p[i] is replaced on day (i + 1), we store day numbers (1-based index).
        vector<int> day(n);
        for (int i = 0; i < n; i++) {
            day[p[i]] = i + 1;
        }

        int min_days = 0;

        // Check all adjacent pairs
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                // We need to wait until the character at index i or i + 1 is replaced.
                // The required day for this pair is the minimum of their replacement days.
                int required_day = min(day[i], day[i + 1]);
                min_days = max(min_days, required_day);
            }
        }

        return min_days;
    }
};
