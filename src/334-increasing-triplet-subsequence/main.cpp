#include <vector>
using namespace std;

// https://leetcode.cn/problems/increasing-triplet-subsequence/
// greedy: O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false; 
        vector<int> q(2, INT_MAX);
        for (auto &x: nums) {
            int k = 2;
            while (k > 0 && x <= q[k - 1]) --k;
            if (k == 2) return true;
            q[k] = x;
        }
        return false;
    }
};