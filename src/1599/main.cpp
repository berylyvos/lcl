#include <vector>
using namespace std;
// https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/

class Solution {
public:
    static constexpr int CABIN_SIZE = 4;

    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size(), profit = 0, maxProfit = 0, waiting = 0, res = -1;
        
        for (int i = 0; i < n || waiting; ++i) {
            waiting += (i < n ? customers[i] : 0);
            int curShift = min(CABIN_SIZE, waiting);
            waiting -= curShift;
            profit += boardingCost * curShift - runningCost;
            if (profit > maxProfit) {
                maxProfit = profit;
                res = i + 1;
            }
        }

        return res;
    }
};