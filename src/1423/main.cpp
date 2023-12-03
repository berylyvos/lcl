#include <vector>
#include <numeric>
using namespace std;
// https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards

// 正：左拿[0, k] 右拿[k, 0] 
// O(k)
class Solution2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int s = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0), res = s;
        for (int i = 0; i < k; ++i) {
            s += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            res = max(res, s);
        }
        return res;
    }
};

// 逆：sum - min(子数组)：滑窗 O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res = 2e9;

        int m = n - k, s = 0;
        for (int i = 0, t = 0; i < n; ++i) {
            s += cardPoints[i];
            t += cardPoints[i];
            if (i >= m) t -= cardPoints[i - m];
            if (i >= m - 1) res = min(res, t);
        }
        
        return s - res;
    }
};