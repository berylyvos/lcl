#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if (n == 0) return res;
        //         3
        //   2 2 2
        // 1
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        if (nums[r] != target) return res;
        res[0] = r;

        r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > target) r = mid - 1;
            else l = mid; // NOTE! => l + r need +1
        }
        res[1] = r;

        return res;
    }
};