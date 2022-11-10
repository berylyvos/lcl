#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int res = 0;
        for (int i = 0, s = 0; i < (int)nums.size(); ++ i) {
            s += nums[i];
            int r = (s % k + k) % k; // 考虑对负数求余数的情况！
            res += cnt[r] ++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    printf("%d\n", Solution().subarraysDivByK(nums, k)); // 7
    return 0;
}