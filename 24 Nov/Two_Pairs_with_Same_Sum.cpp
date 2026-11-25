// Date: 24 Nov 2026
// Problem: Two Pairs with Same Sum
// Difficulty: Medium

class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();
        // Maps sum -> earliest pair of indices {i, j} with i < j
        unordered_map<int, pair<int, int>> sumMap;
        vector<int> ans;

        // Iterate in lexicographical order of pairs (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int currentSum = arr[i] + arr[j];

                if (sumMap.find(currentSum) == sumMap.end()) {
                    // Store only the first occurrence so (a, b) stays lexicographically smallest
                    sumMap[currentSum] = {i, j};
                } else {
                    auto [a, b] = sumMap[currentSum];
                    // Ensure all four indices are strictly distinct
                    if (a != i && a != j && b != i && b != j) {
                        vector<int> candidate = {a, b, i, j};
                        // Update ans if empty or candidate is lexicographically smaller
                        if (ans.empty() || candidate < ans) {
                            ans = candidate;
                        }
                    }
                }
            }
        }

        if (ans.empty()) {
            return {-1, -1, -1, -1};
        }
        return ans;
    }
};
