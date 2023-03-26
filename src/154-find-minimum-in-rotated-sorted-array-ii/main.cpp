#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1]) return nums[0];

        int l = 0, r = n - 1;
        while (r != 0 && nums[r] == nums[0]) --r;
        if (nums[0] <= nums[r]) return nums[0];

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        return nums[r];
    }
};