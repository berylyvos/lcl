#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.cn/problems/count-pairs-of-nodes/description/
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> d(n + 1); // 点的度数
        unordered_map<int, int> cnt; // 边出现次数
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            if (a > b) swap(a, b);
            ++d[a], ++d[b];
            ++cnt[a << 16 | b];
            // ++cnt[a * n + b];
        }

        int m = queries.size();
        vector<int> res(m);
        vector<int> d1 = d;
        sort(d1.begin(), d1.end());
        for (int i = 0; i < m; ++i) {
            int q = queries[i];
            int l = 1, r = n;
            while (l < r) {
                if (d1[l] + d1[r] <= q) ++l;
                else res[i] += r-- - l;
            }
            for (auto &[h, c]: cnt) {
                int s = d[h >> 16] + d[h & 0xffff];
                if (s > q && s - c <= q) --res[i];
            }
        }
        return res;
    }
};