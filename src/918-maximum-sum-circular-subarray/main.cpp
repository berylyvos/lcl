#include <vector>
using namespace std;

// https://leetcode.cn/problems/maximum-sum-circular-subarray/

class Solution2 {
public:
    // case1: [   |maxSub| ]
    // case2: [   |minSub| ] maxSub = sum - minSub
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSub = nums[0], curMax = 0, minSub = nums[0], curMin = 0, s = 0;
        for (int &x: nums) {
            curMax = max(curMax, 0) + x;
            maxSub = max(maxSub, curMax);
            curMin = min(curMin, 0) + x;
            minSub = min(minSub, curMin);
            s += x;
        }
        // corner case : maxSub < 0, meaning all elements < 0, 
        // maxSub is the biggest negtive number in nums.
        return maxSub > 0 ? max(maxSub, s - minSub) : maxSub;
    }
};

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