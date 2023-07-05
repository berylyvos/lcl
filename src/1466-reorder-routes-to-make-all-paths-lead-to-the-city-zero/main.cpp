#include <vector>
using namespace std;

// https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

class Solution {
public:
    int res;

    void dfs(vector<vector<pair<int, bool>>> &g, int u, int pre) {
        for (auto& [v, c]: g[u])
            if (v != pre) {
                if (c) ++res;
                dfs(g, v, u);
            }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> g(n);
        for (auto &c: connections) {
            g[c[0]].emplace_back(c[1], true);
            g[c[1]].emplace_back(c[0], false);
        }
        dfs(g, 0, -1);
        return res;
    }
};