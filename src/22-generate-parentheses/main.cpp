#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/generate-parentheses/

// O((C_n_2n / n + 1) * 2n) = O(C_n_2n)
class Solution {
public:
    int N;
    vector<string> res;

    void dfs(int lc, int rc, string& s) {
        if (lc == N && rc == N) {
            res.emplace_back(s);
            return;
        }
        if (lc < N) {
            s.push_back('(');
            dfs(lc + 1, rc, s);
            s.pop_back();
        }
        if (rc < lc) {
            s.push_back(')');
            dfs(lc, rc + 1, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        string s = "";
        dfs(0, 0, s);
        return res;
    }
};

class Solution1 {
public:
    int N;
    vector<string> res;

    void dfs(int lc, int rc, string s) {
        if (lc == N && rc == N) {
            res.emplace_back(s);
        } else {
            if (lc < N) dfs(lc + 1, rc, s + '(');
            if (rc < lc) dfs(lc, rc + 1, s + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        N = n;
        dfs(0, 0, "");
        return res;
    }
};