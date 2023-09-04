#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range/description/

vector<int> nums[4]; // 位数 2, 4, 6, 8

class Solution {
public:
    // odd/even: 奇偶数数位个数
    // x: 当前数
    void dfs(int odd, int even, int x) {
        // odd == even: 1, 2, 3, 4
        if (odd && odd == even) nums[odd - 1].push_back(x);
        if (odd == 4 && even == 4) return;

        if (x == 0) {
            // 枚举第一位，不能有前导零
            for (int i = 1; i <= 9; ++i)
                if (i & 1) dfs(1, 0, i);
                else dfs(0, 1, i);
        } else {
            for (int i = 0; i <= 9; ++i)
                if (i & 1 && odd < 4) dfs(odd + 1, even, x * 10 + i);
                else if (!(i & 1) && even < 4) dfs(odd, even + 1, x * 10 + i);
        }
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        // 预处理出奇偶数位个数相等的数
        // 首次预处理后，运行下个样例就不用再预处理了，因为全局变量nums不会被清空
        if (nums[0].empty()) dfs(0, 0, 0);

        int res = 0;
        for (auto &x: nums) {
            auto begin = lower_bound(x.begin(), x.end(), low);
            auto end = upper_bound(x.begin(), x.end(), high);
            while (begin != end) {
                if (*begin % k == 0) ++res;
                ++begin;
            }
        }

        return res;
    }
};