#include <vector>
using namespace std;

// 给你一个整数数组 nums 和一个整数 k 。
// 每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。
// 返回你可以对数组执行的最大操作数。
// https://leetcode.cn/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < j;) {
            int s = nums[i] + nums[j];
            if (s == k) ++res, ++i, --j; 
            else if (s < k) ++i;
            else --j;
        }
        return res;
    }
};