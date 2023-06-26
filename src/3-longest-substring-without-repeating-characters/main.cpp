#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int ASCII_MAX = 255;
        int last_idx[ASCII_MAX];
        // memset(last_idx, -1, sizeof last_idx);
        fill(last_idx, last_idx + ASCII_MAX, -1);
        
        int res = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            int last = last_idx[s[i]];
            if (last >= start) start = last + 1;
            res = max(res, i - start + 1);
            last_idx[s[i]] = i;
        }

        return res;
    }
};