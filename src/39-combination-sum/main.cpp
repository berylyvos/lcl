#include <vector>
using namespace std;

// https://leetcode.cn/problems/combination-sum/
// 输入: candidates = [2,3,5], target = 8
// 输出: [[2,2,2,2],[2,3,3],[3,5]]

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
        
        dfs(c, u + 1, s);
        
        if (s >= c[u]) {
            path.emplace_back(c[u]);
            dfs(c, u, s - c[u]);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }
};