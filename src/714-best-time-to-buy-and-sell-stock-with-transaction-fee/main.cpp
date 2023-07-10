#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int INF = 1e8;
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(2, -INF));
        // f[i][0]: 未持有，f[i][1]: 持有（未卖出）
        f[0][0] = 0, f[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i] - fee);
        }

        return max(f[n - 1][0], f[n - 1][1]);
    }
};