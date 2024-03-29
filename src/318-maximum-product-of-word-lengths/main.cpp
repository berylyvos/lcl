#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> f(n, 0);
        for (int i = 0; i < n; ++i)
            for (char& c: words[i]) {
                f[i] |= 1 << (c - 'a');
            }
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (!(f[i] & f[j])) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
        
        return res;
    }
};