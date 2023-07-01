#include <string>
using namespace std;

// https://leetcode.cn/problems/removing-stars-from-a-string/

class Solution {
public:
    // "leet**cod*e" => "lecoe"
    string removeStars(string s) {
        // use s[] itself as stack
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                --k;
            } else {
                s[k++] = s[i];
            }
        }

        return s.substr(0, k);
    }
};