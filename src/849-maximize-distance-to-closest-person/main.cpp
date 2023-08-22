#include <vector>
using namespace std;

// https://leetcode.cn/problems/maximize-distance-to-closest-person/description/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) continue;
            int j = i + 1;
            while (j < n && !seats[j]) ++j;
            if (i == 0 || j == n) res = max(res, j - i);
            else res = max(res, (j - i + 1) / 2);
        }

        return res;
    }
};