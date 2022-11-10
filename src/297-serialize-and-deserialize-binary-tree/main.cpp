#include <cstdio>
#include <string>
#include "headers/tree.h"

using namespace std;

class Codec {
public:
    void dfs_s(TreeNode *cur, string &s) {
        if (!cur) {
            s += "#,";
            return;
        }
        s += to_string(cur->val) + ",";
        dfs_s(cur->left, s);
        dfs_s(cur->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs_s(root, s);
        return s;
    }

    TreeNode* dfs_d(const string& s, int &u) {
        if (s[u] == '#') {
            u += 2;
            return nullptr;
        }
        int k = u;
        while (s[u] != ',') ++ u;
        auto root = new TreeNode(stoi(s.substr(k, u - k)));
        ++ u;
        root->left = dfs_d(s, u);
        root->right = dfs_d(s, u);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }
};

int main() {

    string s = "1,2,3,null,null,4,5";
    auto root1 = deserializeTree(s);

    auto res = Codec().serialize(root1);
    printf("%s\n", res.c_str());
    auto root2 = Codec().deserialize(res);
    res = Codec().serialize(root2);
    printf("%s\n", res.c_str());

    destroyTree(root1);
    destroyTree(root2);
    
    return 0;
}