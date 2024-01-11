#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/

class Solution {
public:
    int minLength(string s) {
        vector<char> st;
        for (char& c: s) {
            st.push_back(c);
            if (st.size() > 1 && ( 
                st[st.size() - 2] == 'A' && st.back() == 'B' ||
                st[st.size() - 2] == 'C' && st.back() == 'D')) {
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};