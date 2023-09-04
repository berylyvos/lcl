#include <vector>
#include <numeric>
using namespace std;
// https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum/

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long s = accumulate(nums.begin(), nums.end(), 0ll);
        if (s < target) return -1;
        sort(nums.begin(), nums.end());

        int n = nums.size(), res = 0;
        while (target) {
            int t = nums.back();
            nums.pop_back();
            if (s - t >= target) s -= t;
            else if (t > target) {
                ++res;
                nums.push_back(t / 2);
                nums.push_back(t / 2);
            } else { // t <= target
                target -= t;
                s -= t;
            }
        }
        return res;
    }
};