#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/rectangle-area/

class Solution {
public:
    int rectangleArea(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int overlap = 0;
        if (bx1 < ax2 && by1 < ay2 && bx2 > ax1 && by2 > ay1) {
            overlap = rectangleArea(max(ax1, bx1), max(ay1, by1), min(ax2, bx2), min(ay2, by2));
        }
        return rectangleArea(ax1, ay1, ax2, ay2) + rectangleArea(bx1, by1, bx2, by2) - overlap;   
    }
};