#include <vector>
using namespace std;
// https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i += 2)
            if (nums[i] == nums[i + 1]) return nums[i];

        return (nums[0] == nums[2] || nums[0] == nums[3]) ? nums[0] : nums[1];
    }
};