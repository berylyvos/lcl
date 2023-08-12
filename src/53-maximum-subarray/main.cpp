#include <cstdio>
#include <vector>

using namespace std;

// #define INT_MIN    - 0x7fffffff - 1
#define INT_MIN    0x80000000
#define INT_MAX    0x7fffffff

struct Node {
    int sum, s, ls, rs; // 当前区间: 总和、最大子段和、最大前缀、最大后缀 
};

class Solution {
public:
    //  DP： O(n) O(1)
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, last = 0;
        for (int &x: nums) {
            last = max(last, 0) + x;
            res = max(res, last);
        }
        return res;
    }
};

class Solution2 {
public:
    // 分治：将当前区间二分，分别对左右子区间求最大子段和，可分为3种情况：
    //      1. 全部在左边
    //      2. 全部在右边
    //      3. 横跨左右两边，左边的最大后缀 + 右边的最大前缀
    Node build(const vector<int>& nums, int i, int j) {
        if (i == j) return {nums[i], nums[i], nums[i], nums[i]};
        int mid = (i + j) >> 1;
        Node l = build(nums, i, mid), r = build(nums, mid + 1, j);
        Node res;
        res.sum = l.sum + r.sum;
        res.s = max(max(l.s, r.s), l.rs + r.ls);
        res.ls = max(l.ls, l.sum + r.ls);
        res.rs = max(r.rs, r.sum + l.rs);
        return res;
    }

    // O(n)：每层的时间复杂度相加：n + n/2 + ... + 1
    // O(logn): 递归栈空间 logn 层
    int maxSubArray(vector<int>& nums) {
        Node res = build(nums, 0, nums.size() - 1);
        return res.s;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", Solution().maxSubArray(nums)); // 6  [4, -1, 2, 1]
    return 0;
}