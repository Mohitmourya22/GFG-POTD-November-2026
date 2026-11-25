#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    inline bool isVowel(char c) const {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = static_cast<int>(s.size());
        // pref[i] stores the number of vowels in s[0 ... i-1]
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (isVowel(s[i]) ? 1 : 0);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto &q : queries) {
            int l = q[0];
            int r = q[1];
            // Vowels in s[l ... r] = vowels in s[0 ... r] - vowels in s[0 ... l-1]
            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};
