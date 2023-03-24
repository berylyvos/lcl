#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        // the rotated sorted array with distinct values
        //     5
        //   4
        // 3
        //          2
        //        1

        // find the min index which is in the interval 
        // that all values < nums[0] 
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // check which side the target is in
        if (target >= nums[0]) {
            l = 0;
        } else {
            r = n - 1;
        }

        // find target
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return target == nums[l] ? l : -1;
    }
};