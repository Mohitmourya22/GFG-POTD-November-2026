// Date: 3 Nov 2026
// Problem: Count Tree Paths With Limited Max Edge Weight
// Difficulty: Hard

class Solution {
  public:
    vector<int> parent, sz;

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];   // path compression (halving)
            x = parent[x];
        }
        return x;
    }

    vector<int> maximumWeight(int n, vector<vector<int>>& edges, vector<int>& queries) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;

        // sort edges by weight
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int q = queries.size();
        vector<pair<int,int>> qs(q);
        for (int i = 0; i < q; i++) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());

        vector<int> ans(q);
        long long paths = 0;
        int ptr = 0, m = edges.size();

        for (auto &[x, idx] : qs) {
            while (ptr < m && edges[ptr][2] <= x) {
                int a = find(edges[ptr][0]);
                int b = find(edges[ptr][1]);
                if (a != b) {
                    paths += 1LL * sz[a] * sz[b];
                    if (sz[a] < sz[b]) swap(a, b);   // union by size
                    parent[b] = a;
                    sz[a] += sz[b];
                }
                ptr++;
            }
            ans[idx] = (int)paths;
        }
        return ans;
    }
};
