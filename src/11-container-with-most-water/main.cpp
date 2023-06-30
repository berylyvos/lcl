#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0;
        
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            // always move the lower one
            (height[i] < height[j]) ? ++i : --j;   
        }

        return res;
    }
};