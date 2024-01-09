#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/extra-characters-in-a-string

// dp 
class Solution1 {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> d(dictionary.begin(), dictionary.end());
        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            for (int j = 0; j < i; ++j)
                if (d.count(s.substr(j, i - j))) {
                    f[i] = min(f[i], f[j]);
                }
        }
        return f[n];
    }
};

// memorized search
class Solution2 {
public:
    vector<int> memo;
    string s;

    int dfs(unordered_set<string>& d, int i) {
        if (memo[i] != -1) return memo[i];

        int res = dfs(d, i - 1) + 1;
        for (int j = 0; j < i; ++j)
            if (d.count(s.substr(j, i - j)))
                res = min(res, dfs(d, j));
        
        memo[i] = res;
        return res;
    }

    int minExtraChar(string ss, vector<string>& dictionary) {
        unordered_set<string> d(dictionary.begin(), dictionary.end());
        s = ss;
        int n = s.size();
        memo.resize(n + 1, -1);
        memo[0] = 0;
        return dfs(d, n);
    }
};