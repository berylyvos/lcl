#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// BFS求无向图两点最短路
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        if (target == start) return 0;

        unordered_set<string> dead (deadends.begin(), deadends.end());
        if (dead.find(start) != dead.end()) return -1;

        queue<string> q;
        unordered_map<string, int> dist;
        q.push(start);
        dist[start] = 0;

        while (q.size()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++ i)
                for (int j = -1; j <= 1; j += 2) {
                    auto next = cur;
                    next[i] = (next[i] - '0' + j + 10) % 10 + '0';

                    if (dead.find(next) != dead.end() || dist.find(next) != dist.end()) continue;

                    dist[next] = dist[cur] + 1;
                    if (next == target) return dist[next];

                    q.push(next);    
                }
        }
        return -1;
    }
};

int main() {
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    printf("%d\n", Solution().openLock(deadends, target));
    // 6
    // "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"
    return 0;
}