// Date: 7 Nov 2026
// Problem: Generate Usernames
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<string> generateUsernames(vector<string>& arr) {
        // 1. Mark all initial names as reserved
        unordered_set<string> reserved(arr.begin(), arr.end());
        
        // Tracks whether the first occurrence of a name has been processed
        unordered_set<string> seen;
        
        // Caches the next candidate integer suffix for each base name
        unordered_map<string, int> next_suffix;
        
        vector<string> result;
        result.reserve(arr.size());
        
        for (const string& name : arr) {
            // Case 1: First time encountering this exact name in the array
            if (seen.find(name) == seen.end()) {
                seen.insert(name);
                result.push_back(name);
            } 
            // Case 2: Duplicate name — find the smallest available suffix
            else {
                int suffix = (next_suffix.count(name)) ? next_suffix[name] : 1;
                string candidate = name + to_string(suffix);
                
                // Increment until we find a username not in the reserved/assigned set
                while (reserved.find(candidate) != reserved.end()) {
                    suffix++;
                    candidate = name + to_string(suffix);
                }
                
                // Mark the new username as reserved and update the suffix tracker
                reserved.insert(candidate);
                next_suffix[name] = suffix + 1;
                result.push_back(candidate);
            }
        }
        
        return result;
    }
};
