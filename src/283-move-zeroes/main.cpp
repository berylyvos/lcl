#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // make j point to the first zero
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                if (i != j) swap(nums[i], nums[j]);
                ++j; 
            } 
            // when nums[i] reaches to 0, nums[j] is already 0, 
            // j do not move to next, pointing to the first zero until being swapped
        }
    }
};