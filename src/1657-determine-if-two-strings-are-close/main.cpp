#include <vector>
#include <string>
using namespace std;

// https://leetcode.cn/problems/determine-if-two-strings-are-close/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        
        const int N = 26;
        vector<int> c1(N, 0), c2(N, 0);
        for (auto &x: word1) c1[x - 'a']++;
        for (auto &x: word2) c2[x - 'a']++;

        // check if c1 & c2 share the same vocabulary
        for (int i = 0; i < N; ++i) {
            if ((c1[i] && !c2[i]) || (!c1[i] && c2[i])) return false;
        }
        
        // check the sorted frequence is the same
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        for (int i = 0; i < N; ++i) {
            if (c1[i] != c2[i]) return false;
        }

        return true;
    }
};