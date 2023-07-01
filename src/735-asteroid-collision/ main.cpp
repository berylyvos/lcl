#include <vector>
using namespace std;

// https://leetcode.cn/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto &x: asteroids) {
            if (x < 0) {
                while (res.size() && res.back() > 0 && res.back() < -x) res.pop_back();
                if (res.empty() || res.back() < 0) res.push_back(x);
                else if (res.back() == -x) res.pop_back();
            } else {
                res.push_back(x);
            }
        }

        return res;
    }
};