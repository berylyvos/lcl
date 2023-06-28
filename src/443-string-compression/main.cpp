#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& s) {
        int idx = 0, cnt = 0, n = s.size();
        int i = 0, j;
        while (i < n) {
            j = i + 1;
            while (j < n && s[j] == s[i]) ++j;
            cnt = j - i;
            s[idx++] = s[i];
            if (cnt > 1) {
                int k = idx;
                while (cnt) {
                    s[idx++] = cnt % 10 + '0';
                    cnt /= 10;
                }
                reverse(s.begin() + k, s.begin() + idx);
            }
            i = j;
        }
        return idx;
    }
};

int main() {
    vector<char> s{'a', 'a', 'a', 'a', 'b', 'c', 'c'};
    int n = Solution().compress(s);
    cout << n <<  '\n'; // 5 "a4bc2"
    for (int i = 0; i < n; ++i) cout << s[i];
    cout << '\n';
}