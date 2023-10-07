#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/jump-game-iv/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; ++i) idx[arr[i]].push_back(i);

        int res = 0;
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int t = q.front(); q.pop();
                if (t == n - 1) return res;
                for (int i = t - 1; i <= t + 1; i += 2)
                    if (i >= 0 && i < n && !vis[i]) {
                        q.push(i);
                        vis[i] = true;
                    }

                int x = arr[t];
                if (idx.find(x) != idx.end()) {
                    for (int &j: idx[x]) if (!vis[j]) {
                        q.push(j);
                        vis[j] = true;
                    }
                    idx.erase(x);
                }
            }
            ++res;
        }
        return res;
    }
};