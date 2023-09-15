#include <vector>
using namespace std;
// https://leetcode.cn/problems/combination-sum-iv/

// 此题和~完全背包求总体积恰为背包容量的方案数~很像，但不一样
// 这里的方案如[1, 2, 2]和[2, 1, 2]是不同的
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; ++i)
            for (int j = 0; j < n; ++j)
                if (nums[j] <= i) f[i] += f[i - nums[j]];
        return f[target];
    }
};