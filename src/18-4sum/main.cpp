//
// Created by Shingo Gnix on 2023/3/8.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        using LL = long long;
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            if (i + 3 < n && (LL)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                if (j + 2 < n && (LL)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                for (int k = j + 1, r = n - 1; k < r; ++k) {
                    if (k > j + 1 && nums[k - 1] == nums[k]) continue;
                    if (k + 1 < n && (LL)nums[i] + nums[j] + nums[k] + nums[k + 1] > target) break;

                    while (k < r - 1 && (LL)nums[i] + nums[j] + nums[k] + nums[r - 1] >= target) --r;
                    if ((LL)nums[i] + nums[j] + nums[k] + nums[r] == target) {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[k], nums[r]});
                    }
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}