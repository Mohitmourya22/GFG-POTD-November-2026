// Date: 1 Nov 2026
// Problem: Maximum Subarray Sum with One Square Allowed
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSubarray(vector<int>& arr) {
        long long no_square = 0;   // Max subarray sum ending here without any square yet
        long long sq_ended = 0;    // Max subarray sum ending here with the square happening right at this element
        long long sq_after = 0;    // Max subarray sum ending here with the square having happened in the past

        long long max_so_far = arr[0];

        no_square = arr[0];
        sq_ended = (long long)arr[0] * arr[0];
        sq_after = sq_ended; // Can also start a squared element immediately

        max_so_far = max({no_square, sq_ended, sq_after});

        for (size_t i = 1; i < arr.size(); ++i) {
            long long val = arr[i];
            long long val_sq = val * val;

            // Previous states
            long long prev_no_square = no_square;
            long long prev_sq_ended = sq_ended;
            long long prev_sq_after = sq_after;

            // 1. Extend or start a new subarray without squaring
            no_square = max(val, prev_no_square + val);

            // 2. Square the current element (either start fresh with squared element or add to previous non-squared subarray)
            sq_ended = max(val_sq, prev_no_square + val_sq);

            // 3. Continue a subarray where a square already happened previously, or square the current element after a past non-squared chain
            sq_after = max({val_sq, prev_sq_after + val, prev_sq_ended + val});

            // Update the global maximum
            max_so_far = max({max_so_far, no_square, sq_ended, sq_after});
        }

        return max_so_far;
    }
};
