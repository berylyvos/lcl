#include <vector>
using namespace std;
// https://leetcode.cn/problems/collecting-chocolates

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        int f[n][n]; // 第i个巧克力进行了j次操作后的最小成本
        // f[i][j] = min(nums[i], nums[i - 1], ..., nums[(i - j + n) % n])
        // f[i][j] = min(f[i][j - 1], nums[(i - j + n) % n])
        for (int i = 0; i < n; ++i) {
            f[i][0] = nums[i];
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i][j - 1], nums[(i - j + n) % n]);
            }
        }
        long long res = (1ull << 63) - 1; // 9223372036854775807
        for (int j = 0; j < n; ++j) {
            long long s = 1ll * j * x;
            for (int i = 0; i < n; ++i) {
                s += f[i][j];
            }
            res = min(res, s);
        }
        return res;
    }
};