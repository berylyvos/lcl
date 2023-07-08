#include <vector>
#include <string>
using namespace std;

// https://leetcode.cn/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        int n = products.size(), k = 0;
        string prefix;
        
        for (auto &c: searchWord) {
            vector<string> res;
            prefix += c;
            while (k < n && products[k] < prefix) ++k;
            for (int i = k; i < n && i < k + 3; ++i) {
                if (products[i].substr(0, prefix.size()) == prefix)
                    res.emplace_back(products[i]);
                else break;
            }
            ans.emplace_back(res);
        }

        return ans;
    }
};