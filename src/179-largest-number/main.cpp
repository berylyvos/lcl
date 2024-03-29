#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 3|30 > 30|3  =>  3 > 30
        // 34|3 > 3|34  =>  34 > 3
        sort(nums.begin(), nums.end(), [&](const int& x, const int& y) {
            string a = to_string(x), b = to_string(y);
            return a + b > b + a;
        });

        if (nums[0] == 0) return "0";

        string res;
        for (int& x: nums) res.append(to_string(x));
        return res;
    }
};