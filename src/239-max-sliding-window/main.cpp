#include <deque>
#include "headers/vector.h"

using namespace std;

// 滑动窗口 + 单调队列 O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++ i) {
            if (q.size() && i - q.front() + 1 > k) q.pop_front();
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    print_vec(Solution().maxSlidingWindow(nums, k));
    // [3,3,5,5,6,7]
    return 0;
}