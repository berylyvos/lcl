#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    
    vector<string> str {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    
    void dfs(string &digits, int u, string s) {
        if (u == digits.size()) {
            res.emplace_back(s);
            return;
        }
        int t = digits[u] - '0';
        for (auto &x: str[t]) {
            dfs(digits, u + 1, s + x);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(digits, 0, "");
        return res;
    }
};