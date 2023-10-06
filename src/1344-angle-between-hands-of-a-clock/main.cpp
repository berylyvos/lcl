#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/angle-between-hands-of-a-clock/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double h = hour * 30 + minutes / 60.0 * 30;
        double m = minutes / 60.0 * 360;
        return min(abs(h - m), 360 - abs(h - m));
    }
};