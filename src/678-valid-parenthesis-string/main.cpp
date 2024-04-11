#include <string>
using namespace std;
// https://leetcode.cn/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        
        for (const char& c: s) {
            if (c == '(') ++low, ++high;
            else if (c == ')') --low, --high;
            else --low, ++high;
            
            low = max(low, 0);
            if (low > high) return false;  
        }

        return low == 0;
    }
};