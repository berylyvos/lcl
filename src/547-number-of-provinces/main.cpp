#include <cstdio>
#include <vector>

using namespace std;

// 并查集：O(n^2 * log(n))
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

int main() {
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    printf("%d\n", Solution().findCircleNum(isConnected)); // 2

    return 0;
}