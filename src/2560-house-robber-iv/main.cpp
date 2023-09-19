#include <vector>
using namespace std;
// https://leetcode.cn/problems/house-robber-iv/

// 二分 + DP
class Solution2 {
public:
    int minCapability(vector<int>& nums, int k) {
        auto check = [&](int x) {
            int f0 = 0, f1 = 0, f2 = 0;
            for (auto& v: nums) {
                if (v <= x) f2 = max(f1, f0 + 1);
                f0 = f1;
                f1 = f2;
                if (f1 >= k) return true;
            }
            return false;
        };

        auto [a, b] = minmax_element(nums.begin(), nums.end());
        int l = *a, r = *b;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

// 二分 + 贪心
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        auto check = [&](int x) {
            int cnt = 0;
            for (int i = 0, j = -2; i < n; ++i)
                if (nums[i] <= x && i - j > 1) {
                    ++cnt;
                    j = i;
                }
            return cnt >= k;
        };

        auto [a, b] = minmax_element(nums.begin(), nums.end());
        int l = *a, r = *b;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};