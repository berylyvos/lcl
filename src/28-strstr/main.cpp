#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Knuth-Morris-Pratt: O(n + m)
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<int> next(m + 1);

        // next[0] = next[1] = 0
        for (int i = 2, j = 0; i <= m; ++ i) {
            while (j && p[i] != p[j + 1]) j = next[j];
            if (p[i] == p[j + 1]) ++ j;
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; ++ i) {
            while (j && s[i] != p[j + 1]) j = next[j];
            if (s[i] == p[j + 1]) ++ j;
            if (j == m) return i - m;
        }

        return -1;
    }
};

int main()
{
    string s = "123abc000", p = "abc";
    cout << Solution().strStr(s, p) << '\n';
    return 0;
}