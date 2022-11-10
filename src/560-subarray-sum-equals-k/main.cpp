#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        int res = 0, s = 0;
        preSum[0] = 1; // s[-1] = 0
        for (auto &x: nums) {
            s += x;
            if (preSum.find(s - k) != preSum.end()) res += preSum[s - k];
            preSum[s] ++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 0, 1};
    int k = 1;
    printf("%d\n", Solution().subarraySum(nums, k)); // 4
    
    return 0;
}