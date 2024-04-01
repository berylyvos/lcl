#include <deque>
#include <string>
using namespace std;
// https://leetcode.cn/problems/faulty-keyboard/

class Solution2 {
public:
    string finalString(string s) {
        deque<char> q;
        bool right = true;
        for (char& c: s) {
            if (c == 'i') right = !right;
            else if (right) q.push_back(c);
            else q.push_front(c);
        }
        return right ? string(q.begin(), q.end()) : string(q.rbegin(), q.rend());
    }
};

class Solution {
public:
    string finalString(string s) {
        string t;
        for (char& c: s) if (c == 'i') {
            reverse(t.begin(), t.end());
        } else {
            t += c;
        }
        return t;
    }
};