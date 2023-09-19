#include <vector>
using namespace std;
// https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/
// 二分求最小的最大值
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        auto check = [&](const int &m) {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i)
                if (nums[i + 1] - nums[i] <= m) {
                    ++cnt;
                    ++i;
                }
            return cnt >= p;
        };

        int l = 0, r = nums[n - 1] - nums[0];
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};