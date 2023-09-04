#include <string>
#include <vector>
#include <sstream>
using namespace std;
// https://leetcode.cn/problems/serialize-and-deserialize-bst/description/?envType=daily-question&envId=2023-09-04
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void dfs_s(TreeNode *cur, string &s) {
        if (!cur) return;
        s += to_string(cur->val) + ' ';
        dfs_s(cur->left, s);
        dfs_s(cur->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs_s(root, s);
        return s;
    }

    TreeNode* dfs_d(const vector<int>& d, int &u, int low, int high) {
        if (u == d.size() || d[u] < low || d[u] > high) return nullptr;
        auto root = new TreeNode(d[u++]);
        root->left = dfs_d(d, u, low, root->val);
        root->right = dfs_d(d, u, root->val + 1, high);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> d;
        stringstream ss(data);
        int x, u = 0;
        while (ss >> x) d.push_back(x); 
        return dfs_d(d, u, -1, 1e5);
    }
};