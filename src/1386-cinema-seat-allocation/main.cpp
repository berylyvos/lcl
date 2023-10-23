#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/cinema-seat-allocation/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 2 * n;
        unordered_map<int, int> reserved; // <行号, 2-9列的状态>
        for (auto& rs: reservedSeats) {
            int x = rs[0], y = rs[1];
            // 若 2-9 列有人了，则当前行最多只能安排 1 个4人家庭
            if (y != 1 && y != 10) reserved[x] |= 1 << (y - 2);
        }
        // 2-9列安排1个4人家庭有三种方法
        const int st[3] = {0b11110000, 0b00111100, 0b00001111};

        res -= 2 * reserved.size();
        for (auto [x, state]: reserved) {
            for (int i = 0; i < 3; ++i)
                if (!(state & st[i])) {
                    ++res;
                    break;
                }
        }
        return res;
    }
};