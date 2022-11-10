#include <string>
#include <vector>
#include <queue>
#include "headers/tree.h"

using namespace std;

// Encodes a tree to a single string.
string serializeTree(TreeNode* root) {
    string res;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t) {
            q.push(t->left);
            q.push(t->right);
            res += to_string(t->val) + ",";
        } else {
            res += "null,";
        }
    }
    return res;
}

static vector<string> split(const string& s, char sep) {
    vector<string> res;
    string tmp;
    for (auto c: s) {
        if (c != sep) {
            tmp += c;
        } else {
            res.emplace_back(tmp);
            tmp.clear();
        }
    }
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserializeTree(string data) {
    vector<string> nodes = split(data + ',', ',');
    if (nodes[0] == "null") return nullptr;
    
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int idx = 1;
    
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        if (nodes[idx] != "null") {
            cur->left = new TreeNode(stoi(nodes[idx]));
            q.push(cur->left);
        }
        ++ idx;
        if (nodes[idx] != "null") {
            cur->right = new TreeNode(stoi(nodes[idx]));
            q.push(cur->right);
        }
        if (++ idx == (int)nodes.size()) break;
    }
    return root;
}

void destroyTree(TreeNode *root) {
    if (!root) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
    root = nullptr;
}