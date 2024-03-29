#include <vector>
using namespace std;
// https://leetcode.cn/problems/rectangle-overlap/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec2[0] < rec1[2] && rec2[1] < rec1[3] && rec2[2] > rec1[0] && rec2[3] > rec1[1]; 
    }
};

class Solution1 {
public:
    bool isLineOverlap(int a, int b, int c, int d) {
        return !(b <= c || d <= a);
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isLineOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) &&
               isLineOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
};