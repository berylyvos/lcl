#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // in this case, the array is still sorted
        if (nums[0] < nums[r]) return nums[0];
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        return nums[r];
    }
};