#include <vector>
#include <set>
using namespace std;

// https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint/
// set + binary search

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int res = 2e9;
        for (int i = x; i < nums.size(); ++i) {
            s.insert(nums[i - x]);
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) res = min(res, *it - nums[i]);
            if (it != s.begin()) res = min(res, nums[i] - *(--it));
        }
        return res;
    }
};