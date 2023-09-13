#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/

// 状态机dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // b1: 第一次买入
        // s1: 第一次卖出
        // b2: 第二次买入
        // s2: 第二次卖出
        int b1 = -prices[0], s1 = 0, b2 = -prices[0], s2 = 0;
        for (int i = 1; i < n; ++i) {
            b1 = max(b1, -prices[i]);
            s1 = max(s1, prices[i] + b1);
            b2 = max(b2, s1 - prices[i]);
            s2 = max(s2, prices[i] + b2);
        }

        return s2;
    }
};

// 前后缀分解：枚举两笔交易的分界点
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