#include <vector>
using namespace std;

// https://leetcode.cn/problems/combination-sum-ii/
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 输出:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void dfs(vector<int>& c, int u, int s) {
        if (s == 0) {
            res.emplace_back(path);
            return;
        }
        if (u == c.size()) return;
        
        // AAB，不选第一个A和第二个A的结果都是B，需要跳过所有A
        int k = u + 1;
        while (k < c.size() && c[k] == c[u]) ++k;
        dfs(c, k, s);
        
        if (s >= c[u]) {
            path.emplace_back(c[u]);
            dfs(c, u + 1, s - c[u]);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};