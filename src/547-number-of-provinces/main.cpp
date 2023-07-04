#include <iostream>
#include <vector>

using namespace std;

// Union-find：O(n^2 * log(n))
class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        p.resize(n);
        for (int i = 0; i < n; ++ i) p[i] = i;
        
        int res = n;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < n; ++ j)
                if (isConnected[i][j] && find(i) != find(j)) {
                    p[find(j)] = find(i);
                    -- res;
                }
        return res;
    }
};

// DFS: O(n^2)
class Solution2 {
public:
    int n, res;
    vector<bool> st;

    void dfs(vector<vector<int>>& g, int u) {
        st[u] = true;
        for (int i = 0; i < n; ++i)
            if (g[u][i] && !st[i]) dfs(g, i);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        st.resize(n);
        for (int i = 0; i < n; ++i)
            if (!st[i]) {
                dfs(isConnected, i);
                ++res;
            }

        return res;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << Solution().findCircleNum(isConnected) << '\n'; // 2

    return 0;
}