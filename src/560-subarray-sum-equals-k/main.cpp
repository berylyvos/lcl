#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int s = 0, res = 0;
        for (int &x: nums) {
            s += x;
            res += cnt[s - k];
            cnt[s]++;
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