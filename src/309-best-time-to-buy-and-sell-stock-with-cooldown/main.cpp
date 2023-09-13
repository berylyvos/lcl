#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // a: 持有
        // b: 冷冻期/无操作
        // c: 当天卖出
        int a = -prices[0], b = 0, c = -1e8, la;
        for (int i = 1; i < n; ++i) {
            la = a;
            a = max(b - prices[i], a);
            b = max(b, c);
            c = la + prices[i];
        }
        return max(a, max(b, c));
    }
};