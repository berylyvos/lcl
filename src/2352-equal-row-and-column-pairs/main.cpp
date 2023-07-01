#include <vector>
#include <map>
using namespace std;

// https://leetcode.cn/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;

        // can not use unordered_map here, for vector<int> is unhashable
        map<vector<int>, int> cnt;
        for (auto &x: grid) cnt[x]++;
        
        for (int i = 0; i < n; ++i) {
            vector<int> col(n);
            for (int j = 0; j < n; ++j) col[j] = grid[j][i];
            if (cnt.find(col) != cnt.end()) res += cnt[col];
        }
        
        return res;
    }
};