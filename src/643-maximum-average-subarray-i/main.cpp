#include <vector>
using namespace std;

// 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
// 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
// 任何误差小于 10^(-5) 的答案都将被视为正确答案。
// 链接：https://leetcode.cn/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = 0;
        for (int i = 0; i < k; ++i) s += nums[i];
        int res = s;
        for (int i = k; i < nums.size(); ++i) {
            s += nums[i] - nums[i - k];
            res = max(res, s);
        }
        return (double)res / k;
    }
};