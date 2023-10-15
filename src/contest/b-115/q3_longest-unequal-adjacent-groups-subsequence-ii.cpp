#include <vector>
#include <string>
using namespace std;
// https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/

// LIS alternative
class Solution {
public:
    bool check(const string& a, const string& b) {
        if (a.size() != b.size()) return false;
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) {
            if (++cnt > 1) return false;
        }
        return cnt == 1;
    }

    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> f(n, 1), g(n, -1);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (groups[j] != groups[i] && check(words[i], words[j])) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = j;
                    }
                }
            if (f[i] > f[k]) k = i;
        }

        vector<string> res;
        while (~k) {
            res.push_back(words[k]);
            k = g[k];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};