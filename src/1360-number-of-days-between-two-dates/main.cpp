#include <string>
using namespace std;
// https://leetcode.cn/problems/number-of-days-between-two-dates/

class Solution {
public:
    const int month[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    int leapDay(int y) {
        return !(y % 400) || !(y % 4) && y % 100;
    }

    int days(string date) {
        int y, m, d;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        int s = 0;
        for (int i = 1971; i < y; ++i) s += leapDay(i) + 365;
        for (int i = 0; i < m - 1; ++i) s += month[i];
        return s + d + (m > 2 && leapDay(y));
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(days(date1) - days(date2));
    }
};