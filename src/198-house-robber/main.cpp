#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        
        // f[i]: 一定偷 nums[i]
        // g[i]：一定不偷 nums[i]
        int f = 0, g = 0;

        for (int i = 0; i < n; ++ i) {
            int last_f = f, last_g = g;
            f = last_g + nums[i];
            g = max(last_f, last_g);
        }
        return max(f, g);
    }

    int rob2(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums[0];
        int f[n];
        memset(f, 0, sizeof f);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++ i)
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        return f[n - 1];
    }
};

int main() {
    vector<int> a = {1, 2, 3, 1};
    printf("%d\n", Solution().rob2(a)); // 4
    return 0;
}