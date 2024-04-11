#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/k-closest-points-to-origin/

class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k - 1, points.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

class Solution {
public:
    int dist(const vector<int>& a) {
        return a[0] * a[0] + a[1] * a[1];
    }

    void qselect(vector<vector<int>>& p, const int& k, int l, int r) {
        if (l >= r) return;

        int i = l - 1, j = r + 1;
        int x = (dist(p[l]) + dist(p[r])) / 2;
        while (i < j) {
            while (dist(p[--j]) > x);
            while (dist(p[++i]) < x);
            if (i < j) swap(p[i], p[j]);
        }

        if (k <= j) return qselect(p, k, l, j);
        else return qselect(p, k, j + 1, r);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        --k;
        qselect(points, k, 0, points.size() - 1);
        return vector<vector<int>>(points.begin(), points.begin() + k + 1);
    }
};