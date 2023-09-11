#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// https://leetcode.cn/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> S(wordDict.begin(), wordDict.end());
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 0; i < n; ++i)
            if (f[i])
                for (int j = n; j > i; --j)
                    if (!f[j] && S.find(s.substr(i, j - i)) != S.end())
                        f[j] = true;
        return f[n];
    }
};

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        using ull = unsigned long long;
        ull h;
        const int P = 131;
        unordered_set<ull> S;
        for (auto &w: wordDict) {
            h = 0;
            for (auto &c: w) h = h * P + c;
            S.insert(h);
        }
        
        int n = s.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 0; i < n; ++i)
            if (f[i]) {
                h = 0;
                for (int j = i + 1; j <= n; ++j) {
                    h = h * P + s[j - 1];
                    if (S.find(h) != S.end()) f[j] = true;
                }
            }

        return f[n];
    }
};