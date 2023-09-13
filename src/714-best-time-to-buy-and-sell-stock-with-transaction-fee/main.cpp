#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // a: 持有
        // b: 已卖出/未持有
        int a = -prices[0] - fee, b = 0;
        for (int i = 1; i < n; ++i) {
            a = max(a, b - prices[i] - fee);
            b = max(b, a + prices[i]);
        }
        return b;
    }
};