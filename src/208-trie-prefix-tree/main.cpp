#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode*> son;
    bool isEnd;
    TrieNode() : isEnd(false), son(26) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto p = root;
        for (auto &c: word) {
            auto &u = p->son[c - 'a'];
            if (u == nullptr) 
                u = new TrieNode();
            p = u;
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        auto node = find(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode *root;

    TrieNode* find(const string& s) {
        auto p = root;
        for (auto &c: s) {
            auto u = p->son[c - 'a'];
            if (u == nullptr) return nullptr;
            p = u;
        }
        return p;
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