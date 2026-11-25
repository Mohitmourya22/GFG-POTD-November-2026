// Date: 4 Nov 2026
// Problem: XOR of All Subarray XORs
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();

        // If the size of the array is even, the XOR of all subarray XORs is always 0.
        if (n % 2 == 0) {
            return 0;
        }

        int result = 0;
        // If n is odd, XOR all elements at even indices (0, 2, 4, ...)
        for (int i = 0; i < n; i += 2) {
            result ^= arr[i];
        }

        return result;
    }
};
