#include <vector>
using namespace std;

// https://leetcode.cn/problems/maximum-sum-circular-subarray/

class Solution {
public:
    // case1: [   |maxSub| ]  LC.53 https://leetcode.cn/problems/maximum-subarray/
    // case2: [leftMax|    |suffix]
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        int pre = nums[0], sub = nums[0], res = nums[0];
        for (int i = 1; i < n; ++i) {
            sub = max(sub, 0) + nums[i];
            res = max(res, sub);
            pre += nums[i];
            leftMax[i] = max(leftMax[i - 1], pre);
        }

        pre = 0;
        for (int i = n - 1; i > 0; --i) {
            pre += nums[i];
            res = max(res, leftMax[i - 1] + pre);
        }

        return res;
    }
};