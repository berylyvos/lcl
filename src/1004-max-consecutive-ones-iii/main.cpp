#include <vector>
using namespace std;

// 给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。
// https://leetcode.cn/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, cnt = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (!nums[i]) ++cnt;
            // matain number of zero <= k in sliding window
            while (cnt > k) {
                if (!nums[j++]) --cnt;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};