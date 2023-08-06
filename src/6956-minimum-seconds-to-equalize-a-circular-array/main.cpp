#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < 2 * n; ++i) idx[nums[i % n]].emplace_back(i);
        
        int ans = n;
        for (auto &[x, id]: idx) {
            int sec = 0;
            for (int i = 0, sz = id.size() / 2; i < sz; ++i) {
                sec = max(sec, (id[i + 1] - id[i]) / 2);
            }
            ans = min(ans, sec);
        }

        return ans;
    }
};