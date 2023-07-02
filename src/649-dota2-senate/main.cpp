#include <string>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/dota2-senate/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();
        for (int i = 0; i < n; ++i)
            (senate[i] == 'R') ? r.push(i) : d.push(i);
        
        while (r.size() && d.size()) {
            int pr = r.front(), pd = d.front();
            (pr < pd) ? r.push(pr + n) : d.push(pd + n); 
            r.pop(), d.pop();
        }

        return r.size() ? "Radiant" : "Dire";
    }
};