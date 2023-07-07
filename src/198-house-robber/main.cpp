#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // f[i]: 一定偷 nums[i]
        // g[i]：一定不偷 nums[i]
        int f = nums[0], g = 0;

        for (int i = 1; i < n; ++i) {
            int pf = f, pg = g;
            f = nums[i] + pg;
            g = max(pf, pg);
        }
        
        return max(f, g);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums[0]; 
        vector<int> f(n);
        f[0] = nums[0], f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            f[i] = max(nums[i] + f[i - 2], f[i - 1]);
        }
        return f[n - 1];
    }
};

int main() {
    vector<int> nums{1, 2, 3, 1};
    cout << Solution2().rob(nums) << '\n'; // 4
    return 0;
}