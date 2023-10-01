#include <vector>
using namespace std;
// https://leetcode.cn/problems/maximum-number-of-k-divisible-components/

// Tip: values 之和可以被 k 整除
class Solution {
public:
    using ll = long long;

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int res = 0;
        function<ll(int,int)> dfs = [&](int u, int pre) -> ll {
            ll s = values[u];
            for (int &j: g[u])
                if (j != pre) s += dfs(j, u);

            res += s % k == 0;
            return s;
        };

        dfs(0, -1);
        return res;
    }
};