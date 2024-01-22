#include <string>
using namespace std;
// https://leetcode.cn/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i + 1 < n; ++i)
            if (s[i] < s[i + 1]) {
                int k = i + 1;
                for (int j = k; j < n; ++j)
                    if (s[j] >= s[k]) k = j;
                    
                for (int j = 0; ; ++j)
                    if (s[j] < s[k]) {
                        swap(s[j], s[k]);
                        return stoi(s);
                    }
            }
        
        return num;
    }
};