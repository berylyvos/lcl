#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://leetcode.cn/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> v;
        unordered_map<string, unordered_map<string, double>> d;
        for (int i = 0; i < equations.size(); ++i) {
            auto a = equations[i][0], b = equations[i][1];
            d[a][b] = values[i], d[b][a] = 1 / values[i];
            v.insert(a), v.insert(b);
        }

        // floyd
        for (auto &k: v)
            for (auto &i: v)
                for (auto &j: v)
                    if (d[i][k] && d[k][j])
                        d[i][j] = d[i][k] * d[k][j];
        
        int n = queries.size();
        vector<double> res(n);
        for (int i = 0; i < n; ++i) {
            auto a = queries[i][0], b = queries[i][1];
            res[i] = d[a][b] ? d[a][b] : -1;
        }

        return res;
    }
};