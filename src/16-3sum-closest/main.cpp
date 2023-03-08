//
// Created by Shingo Gnix on 2023/3/8.
//

//给你一个长度为 n 的整数数组nums和 一个目标值target。请你从 nums 中选出三个整数，使它们的和与target最接近。
//
//返回这三个数的和。
//
//假定每组输入只存在恰好一个解。

#include <vector>
using namespace std;

// 排序 + 双指针：O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int closest = abs(res - target);

        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s == target) return s;

                int diff = abs(s - target);
                if (diff < closest) {
                    closest = diff;
                    res = s;
                }

                if (s > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};
