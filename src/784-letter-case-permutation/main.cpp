#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/letter-case-permutation/

class Solution {
public:
    vector<string> res;

    void dfs(string& s, int u) {
        if (u == s.size()) {
            res.emplace_back(s);
            return;
        }

        dfs(s, u + 1);
        
        if (!isdigit(s[u])) {
            s[u] ^= 32;
            dfs(s, u + 1);
            s[u] ^= 32;
        }
    }

    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return res;
    }
};