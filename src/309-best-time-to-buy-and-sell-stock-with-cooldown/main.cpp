#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int INF = 1e8;
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3, -INF));
        // f[i][0]: 冷冻期，f[i][1]: 已买入，f[i][2]: 当天卖出
        f[0][0] = 0, f[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2]);
            f[i][1] = max(f[i - 1][0] - prices[i], f[i - 1][1]);
            f[i][2] = f[i - 1][1] + prices[i];
        }
        
        return max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2]));
    }
};