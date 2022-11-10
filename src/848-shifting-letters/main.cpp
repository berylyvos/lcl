#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 前缀和
class Solution {
public:
    inline void shift(char &c, int n) {
        c = (c - 'a' + n) % 26 + 'a';
    }
    
    string shiftingLetters(string s, vector<int>& shifts) {
        int count = 0;
        for (int i = shifts.size() - 1; i >= 0; -- i) {
            count = (count + shifts[i]) % 26;
            shift(s[i], count);
        }
        return s;
    }
};

int main()
{
    string s = "aaa";
    vector<int> shifts = {1,2,3};
    printf("%s\n", Solution().shiftingLetters(s, shifts).c_str());
    //  a a a
    //+ 6 5 3
    //  g f d
    return 0;
}