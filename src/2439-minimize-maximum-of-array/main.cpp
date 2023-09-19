#include <vector>
using namespace std;
// https://leetcode.cn/problems/minimize-maximum-of-array/

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        // 模拟：从数组尾开始，不断将大于 m 的部分累加，向前传递，在小于 m 的地方释放
        auto check = [&](const int& m) {
            long long t = 0;
            for (int i = n - 1; i > 0; --i)
                t = max(0ll, t + nums[i] - m);
            return nums[0] + t <= m;
        };
        // 二分出最小的满足条件的最大值
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};