//
// Created by Shingo Gnix on 2023/3/8.
//
#include <iostream>
#include <vector>
using namespace std;

// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
//
// 注意：答案中不可以包含重复的三元组。

// 排序 + 双指针：O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1, k = n - 1; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int a = nums[i], b = nums[j];
                // find the minimum k which satisfy a + b + c >= 0
                while (j < k - 1 && a + b + nums[k - 1] >= 0) --k;
                if (a + b == -nums[k]) {
                    res.emplace_back(vector<int>{a, b, nums[k]});
                }
            }
        }

        return res;
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s < 0) {
                    ++j;
                } else if (s > 0) {
                    --k;
                } else {
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    // j, k jump to the position where do not duplicate with current
                    do { ++j; } while (j < k && nums[j - 1] == nums[j]);
                    do { --k; } while (k > j && nums[k + 1] == nums[k]);
                }
            }
        }

        return res;
    }
};

int main() {
    auto nums = vector<int>{-1,0,1,2,-1,-4};
    auto res = Solution().threeSum2(nums);
    for (auto v : res) {
        for (auto x : v) cout << x << ", ";
        cout << endl;
    }
    // -1, -1, 2,
    // -1, 0, 1,
    return 0;
}