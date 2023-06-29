// https://leetcode.cn/problems/can-place-flowers/
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        for (int i = 0; i < sz; ++i) {
            if (!flowerbed[i] && 
                (i == 0 || !flowerbed[i - 1]) && 
                (i == sz - 1 || !flowerbed[i + 1])) {
                    flowerbed[i] = 1;
                    if (--n <= 0) return true;
                }
        }
        return n <= 0;
    }
};