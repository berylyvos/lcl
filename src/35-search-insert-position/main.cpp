#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // NOTE: r could be nums.size()
        // as the insert position's range is [0, n] 
        int l = 0, r = nums.size();

        // find the min index k that satisfy nums[k] >= target
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1; 
        }

        return r;
    }
};