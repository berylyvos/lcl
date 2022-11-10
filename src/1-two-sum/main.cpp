#include <unordered_map>
#include "headers/vector.h"

using namespace std;

// 哈希表：O(n) O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rec;
        for (int i = 0; i < (int)nums.size(); ++ i) {
            int x = target - nums[i];
            if (rec.find(x) != rec.end()) return vector<int>({rec[x], i});
            rec[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main() {
    vector<int> nums = {0, 2, 3, 0};
    int target = 0;
    print_vec(Solution().twoSum(nums, target));
    
    return 0;
}