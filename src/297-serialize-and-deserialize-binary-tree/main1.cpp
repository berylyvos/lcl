#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 层序遍历
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
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

    vector<string> split(const string& s, char sep) {
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
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data, ',');
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
};

int main()
{
    string s = "1,2,3,null,null,4,5,";
    auto root = Codec().deserialize(s);
    auto res = Codec().serialize(root);
    printf("%s\n", res.c_str());
    return 0;
}