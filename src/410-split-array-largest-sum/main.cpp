#include <vector>
using namespace std;
// https://leetcode.cn/problems/split-array-largest-sum

class Solution {
public:
    bool check(vector<int>& nums, int k, int m) {
        int s = 0, cnt = 1;
        for (int& x: nums) {
            if (x > m) return false;
            else if (s + x > m) {
                ++cnt;
                s = x;
            } else {
                s += x;
            }
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, k, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};