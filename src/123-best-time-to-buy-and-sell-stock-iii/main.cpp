#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;

        // f[i]: 前 i 天进行一次交易的最大利润
        vector<int> f(n + 1);
        for (int i = 1, buy = INT_MAX; i <= n; ++i) {
            f[i] = max(f[i - 1], prices[i - 1] - buy);
            buy = min(buy, prices[i - 1]);
        }

        // 第二笔交易第 i 天买入，维护 >i 天的最大卖出价
        // 总利润 = 前 i - 1 天第一笔交易的最大利润 + 第二笔交易最大利润
        for (int i = n, sold = 0; i >= 1; --i) {
            res = max(res, sold - prices[i - 1] + f[i - 1]);
            sold = max(sold, prices[i - 1]);
        }

        return res;
    }
};