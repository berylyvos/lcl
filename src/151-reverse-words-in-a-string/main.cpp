#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // +-------------------+
    // |  the sky is blue  |
    // |  eht yks si eulb  |
    // |  blue is sky the  |
    // + ------------------+
    string reverseWords(string s) {
        int n = s.size(), k = 0;
        // __the_sky__is___blue_ => eht_yks_si_eulb
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            int j = i, t = k;
            while (j < n && s[j] != ' ') s[t++] = s[j++];
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t;
            i = j;
        }

        // eht_yks_si_eulb => blue_is_sky_the
        s.erase(s.begin() + k - 1, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    string s = "   hello  world    ";
    cout << '"' << Solution().reverseWords(s) << "\"\n"; // "world hello"
}