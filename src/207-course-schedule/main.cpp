#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// 拓扑排序 O(点数 + 边数)
// 1. 将先修关系构成一张图，由每个数对的第二个数字向第一个数字连边。
// 2. 首先将所有入度为 0 的点进队，准备用宽度优先搜索进行拓扑排序。
// 3. 宽搜过程中，将当前结点所关联的结点的入度减 1；若发现新的入度为 0 的结点，则将其进队。
// 4. 最后如果遍历了所有结点，则说明可以满足要求；否则，先修关系存在环。
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);  // 有向图
        vector<int> d(numCourses);          // 入度
        
        for (const auto &p: prerequisites) {
            auto a = p[0], b = p[1];
            g[b].push_back(a);   // b -> a
            d[a] ++;
        }

        // 将入度为0的点入队
        queue<int> q;
        for (int i = 0; i < numCourses; ++ i)
            if (!d[i]) q.push(i);
        
        // 出队元素的个数，若等于总节点数，说明存在拓扑序列
        int cnt = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            ++ cnt; 
            for (const auto &x: g[t])
                if (-- d[x] == 0) q.push(x);
        }
        return cnt == numCourses;
    }
};

int main()
{
    // 0 <-> 1
    vector<vector<int>> prerequisites1 = {{1,0},{0,1}};
    printf("%d\n", Solution().canFinish(2, prerequisites1));

    //   1 -> 2
    //   ↑  、↑
    //    \  /
    //     0
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 1}, {2, 0}};
    printf("%d\n", Solution().canFinish(3, prerequisites2));

    return 0;
}