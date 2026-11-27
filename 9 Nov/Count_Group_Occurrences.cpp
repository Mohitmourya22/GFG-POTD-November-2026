// Date: 9 Nov 2026
// Problem: Count Group Occurrences
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getCount(string &s, int k) {
        int groups[26] = {0};
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            // Increment group count only at the start of a new consecutive block
            if (i == 0 || s[i] != s[i - 1]) {
                groups[s[i] - 'a']++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (groups[i] == k) {
                ans++;
            }
        }
        
        return ans;
    }
};
