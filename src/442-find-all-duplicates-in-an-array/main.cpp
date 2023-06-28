// 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 1次 或 2次 。
// 请你找出所有出现 2次 的整数，并以数组形式返回。
// 你必须设计并实现一个时间复杂度为 O(n) 且仅使用 常量额外空间 的算法解决此问题。
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int &x: nums) {
            int p = abs(x) - 1;
            nums[p] *= -1;
            if (nums[p] > 0) res.push_back(abs(x));
        }
        return res;
    }
};