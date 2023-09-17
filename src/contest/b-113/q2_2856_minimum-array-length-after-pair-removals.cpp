#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/minimum-array-length-after-pair-removals/

// 设nums中众数的出现次数：m
// 若 m > n / 2: 
//      则能和众数消除的数有 n - m 个，剩余 n - 2(n - m) = 2m - n
// 若 m <= n / 2:
//      则能和众数消除的数有 m 个，剩余 n - 2m 个数:
//          若 n 为偶数：n - 2m 也为偶数，可全部消除，余0;
//          若 n 为奇数：n - 2m 为奇数，余1
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size(), x = nums[n >> 1];
        int m = upper_bound(nums.begin(), nums.end(), x) - 
                lower_bound(nums.begin(), nums.end(), x);
        return max(2 * m - n, n & 1);
    }
};