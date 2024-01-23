#include <vector>
using namespace std;
// https://leetcode.cn/problems/longest-alternating-subarray

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), res = -1;
        for (int i = 0; i + 1 < n; ++i)
            if (nums[i + 1] - nums[i] == 1) {
                int j = i + 2, t = 1;
                while (j < n && nums[j] - nums[j - 1] == -t) {
                    ++j;
                    t = -t;
                }
                res = max(res, j - i);
                i = j - 2;
            }
        
        return res;
    }
};