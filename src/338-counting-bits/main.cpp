#include <vector>
using namespace std;

// O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; ++i) {
            int cnt = 0, j = i;
            while (j) {
                j &= (j - 1);
                ++cnt;
            }
            res[i] = cnt;
        }
        return res;
    }
};

// [dp]: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; ++i)
            res[i] = res[i & (i - 1)] + 1;
        return res;
    }
};