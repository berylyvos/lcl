#include <vector>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/keys-and-rooms/

class Solution {
public:
    vector<bool> st;
    int n, vis = 0;

    void dfs(vector<vector<int>> &g, int u) {
        ++vis;
        st[u] = true;
        for (auto &x: g[u])
            if (!st[x]) dfs(g, x);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        st.resize(n);
        dfs(rooms, 0);
        return vis == n;
    }
};

class Solution2 {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<bool> st(n);
        while (q.size()) {
            auto u = q.front();
            q.pop();
            st[u] = true;
            for (auto &x: rooms[u])
                if (!st[x]) q.push(x);
        }

        for (auto v: st)
            if (!v) return false;
        return true;
    }
};