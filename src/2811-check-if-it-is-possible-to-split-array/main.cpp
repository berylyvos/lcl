#include <vector>
using namespace std;

// https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 1 || n == 2) return true;

        // 若存在一长为2的子数组[a, b]满足 a + b >= m
        // 则以[a, b]为“洋葱的核心”，一个一个去处两边的元素，
        // 整个过程都满足[.., a, b, ..]的和 >= m
        for (int i = 0; i + 1 < n; ++i)
                if (nums[i] + nums[i + 1] >= m) return true;

        return false;
    }
};