#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        // deduplicate to make sure that
        // all elements in the second interval < nums[0] 
        while (r!=0 && nums[r] == nums[0]) --r;
        if (r == 0) return target == nums[0];

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        
        if (target >= nums[0]) l = 0;
        else r = n - 1;

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        return target == nums[r];
    }
};