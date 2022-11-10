#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int robRange(const vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int f = 0, g = 0;
        for (int i = l; i <= r; ++ i) {
            int last_f = f, last_g = g;
            f = nums[i] + last_g;
            g = max(last_f, last_g);
        }
        return max(f, g);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};

int main() {
    vector<int> a = {1, 3, 1};
    printf("%d\n", Solution().rob(a)); // 3
    return 0;
}