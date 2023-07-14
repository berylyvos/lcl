#include <vector>
using namespace std;

// https://leetcode.cn/problems/divide-two-integers/

class Solution {
public:
    int divide(int x, int y) {
        const int HALF_INT_MIN = -(1 << 30); // -1073741824
        bool minus = (x > 0) ^ (y > 0);
        if (x > 0) x = -x;
        if (y > 0) y = -y;

        vector<pair<int, int>> t;
        for (int i = y, j = -1; i >= x; i += i, j += j) {
            t.emplace_back(i, j);
            if (i < HALF_INT_MIN) break;
        }
        
        int res = 0;
        for (int i = t.size() - 1; i >= 0; --i) {
            auto [a, b] = t[i];
            if (x <= a) {
                x -= a;
                res += b;
            }
        }

        if (minus) return res;
        else {
            if (res == INT_MIN) return INT_MAX;
            return -res;
        }
    }
};

class Solution2 {
public:
    int divide(int x, int y) {
        const int HALF_INT_MIN = -(1 << 30); // -1073741824
        bool minus = (x > 0) ^ (y > 0);
        if (x > 0) x = -x;
        if (y > 0) y = -y;

        int res = 0;
        while (x <= y) {
            int i = y, j = -1;
            while (i >= HALF_INT_MIN && i >= x - i) {
                i += i, j += j;
            } 
            x -= i;
            res += j;
        }

        if (minus) return res;
        else {
            if (res == INT_MIN) return INT_MAX;
            return -res;
        }
    }
};