#include <vector>
using namespace std;

// https://leetcode.cn/problems/corporate-flight-bookings/

class Solution {
public:
    void add(vector<int>& b, int i, int j, int c) {
        b[i] += c;
        b[j + 1] -= c;
    }

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> b(n + 1);
        for (auto &x: bookings) add(b, x[0] - 1, x[1] - 1, x[2]);
        for (int i = 1; i < n; ++i) b[i] += b[i - 1];
        b.pop_back();
        return b;
    }
};