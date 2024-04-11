#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int res = 1, up = 1, down = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] < arr[i]) {
                up = down + 1;
                down = 1;
            } else if (arr[i - 1] > arr[i]) {
                down = up + 1;
                up = 1;
            } else {
                up = down = 1;
            }
            res = max(res, max(up, down));
        }
        return res;
    }
};