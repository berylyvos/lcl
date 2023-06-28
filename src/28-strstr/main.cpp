#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Knuth-Morris-Pratt: O(n + m)
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ne(m);

        ne[0] = -1;
        for (int i = 1, j = -1; i < m; ++i) {
            while (~j && p[i] != p[j + 1]) j = ne[j];
            if (p[i] == p[j + 1]) ++j;
            ne[i] = j;
        }

        for (int i = 0, j = -1; i < n; ++i) {
            while (~j && s[i] != p[j + 1]) j = ne[j];
            if (s[i] == p[j + 1]) ++j;
            if (j == m - 1) return i - j;
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