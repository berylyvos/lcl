#include <vector>
using namespace std;

// [greedy & dp]
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = 0;

        for (int i = 1, j = 0; i < n; ++i) {
            while (j < i && j + nums[j] < i) ++j;
            f[i] = f[j] + 1;
        }

        return f[n - 1];
    }
};