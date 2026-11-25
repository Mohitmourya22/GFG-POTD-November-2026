// Date: 2 Nov 2026
// Problem: Largest Sum Cycle
// Difficulty: Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSumCycle(vector<int>& edge) {
        int n = edge.size();
        vector<int> vis(n, 0); // 0: unvisited, 1: visiting, 2: visited
        long long maxSum = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int curr = i;
                vector<int> path;

                // Traverse the path
                while (curr != -1 && vis[curr] == 0) {
                    vis[curr] = 1;
                    path.push_back(curr);
                    curr = edge[curr];
                }

                // If we found a cycle (curr is currently being visited in this path)
                if (curr != -1 && vis[curr] == 1) {
                    long long currentCycleSum = 0;
                    bool startCounting = false;

                    for (int node : path) {
                        if (node == curr) {
                            startCounting = true;
                        }
                        if (startCounting) {
                            currentCycleSum += node;
                        }
                    }
                    maxSum = max(maxSum, currentCycleSum);
                }

                // Mark all nodes in the current path as fully visited (2)
                for (int node : path) {
                    vis[node] = 2;
                }
            }
        }

        return maxSum;
    }
};
