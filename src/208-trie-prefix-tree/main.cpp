#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

class Trie {
private:
    struct Node {
        Node *son[26];
        bool isEnd;
        Node() {
            memset(son, 0, sizeof son);
            isEnd = false;
        }
    } *root;

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 26; ++ i)
                if (t->son[i]) {
                    q.push(t->son[i]);
                    t->son[i] = nullptr;
                }
            delete t;
        }
    }
    
    void insert(string word) {
        auto p = root;
        for (auto &c: word) {
            auto u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        auto p = root;
        for (auto &c: word) {
            auto u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto p = root;
        for (auto &c: prefix) {
            int u = c - 'a';
            if (!p->son[u]) return false;
            p = p->son[u];
        }
        return true;
    }
};

int main()
{
    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("apple") << '\n';    // 1
    cout << trie.search("app") << '\n';      // 0
    cout << trie.startsWith("app") << '\n';  // 1
    return 0;
}