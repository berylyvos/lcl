#include <vector>
using namespace std;

// https://leetcode.cn/problems/find-the-losers-of-the-circular-game/

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> losers;
        vector<bool> st(n, false);
        for (int i = 0, j = k; !st[i]; j += k) {
            st[i] = true;
            i = (i + j) % n;
        }
        for (int i = 0; i < n; ++i) 
            if (!st[i]) losers.push_back(i + 1);
        return losers;
    }
};