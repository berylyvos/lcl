#include <cstdio>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/house-robber-ii/

class Solution {
public:
    int robRange(vector<int>& a, const int& l, const int& r) {
        if (l == r) return a[r];
        int n = r - l + 1;
        int f = a[l], g = 0, f1;
        for (int i = l + 1; i <= r; ++i) {
            f1 = f;
            f = a[i] + g;
            g = max(f1, g);
        }
        return max(f, g);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robRange(nums, 1, n - 1), robRange(nums, 0, n - 2));
    }
};

int main() {
    vector<int> a = {1, 3, 1};
    printf("%d\n", Solution().rob(a)); // 3
    return 0;
}