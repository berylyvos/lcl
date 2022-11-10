#include <algorithm>
#include "headers/vector.h"

using namespace std;

class Solution {
private:
    vector<int> nums, orig;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->orig.resize(nums.size());
        copy(nums.begin(), nums.end(), orig.begin());
    }
    
    vector<int> reset() {
        copy(orig.begin(), orig.end(), nums.begin());
        return nums;
    }
    
    // 对第 0 个位置，交换 a[0] 和 a[0,…,n−1]，有 n 种可能；
    // 对第 1 个位置，交换 a[1] 和 a[1,…,n−1]，有 n - 1 种可能；
    // 得到打乱后的数组的概率为：1 / n!
    vector<int> shuffle() {
        int n = nums.size();
        for (int i = 0; i < n; ++ i) {
            swap(nums[i], nums[i + rand() % (n - i)]);
        }
        return nums;
    }
};

int main() {
    vector<int> a = {1, 2, 3};
    Solution solution = Solution(a);
    print_vec(solution.shuffle());    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
    print_vec(solution.reset());      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
    print_vec(solution.shuffle());    // 随机返回数组 [1, 2, 3] 打乱后的结果。

    return 0;
}