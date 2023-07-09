#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for (auto &p: prices) {
            res = max(res, p - buy);
            buy = min(buy, p);
        }
        return res;
    }
};