// https://leetcode.cn/problems/number-of-ways-to-buy-pens-and-pencils/

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2) return waysToBuyPensPencils(total, cost2, cost1);
        long long res = 0;
        for (int i = 0; i * cost1 <= total; ++i) {
            int s = total - i * cost1;
            res += s / cost2 + 1;
        }
        return res;
    }
};