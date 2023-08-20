#include <vector>
using namespace std;
// https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        vector<vector<int>> g(n); // 按右端点分组
        for (int i = 0; i < m; ++i) g[offers[i][1]].push_back(i);

        vector<int> f(n + 1);
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1]; // 不选第i个
            // 选第i个，则只能从f[left-1]转移，left为i的左端点
            for (auto &j: g[i - 1]) f[i] = max(f[i], f[offers[j][0]] + offers[j][2]);
        }

        return f[n];
    }
};