#include <vector>
using namespace std;

// https://leetcode.cn/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void dfs(int u, int s, int k) {
        if (k == 0) {
            if (s == 0) res.emplace_back(path);
            return;
        }
        if (u > 9) return;
        
        dfs(u + 1, s, k);
        
        if (s >= u) {
            path.emplace_back(u);
            dfs(u + 1, s - u, k - 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, n, k);
        return res;
    }
};