#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/lfu-cache/

struct Node {
    int key, val, cnt;
    Node *left, *right;
    Node() {}
    Node(int k, int v): key{k}, val{v}, cnt{1}, left{nullptr}, right{nullptr} {}
};

struct List {
    Node *L, *R;
    int cnt;
    List (int c): L{new Node()}, R{new Node()}, cnt{c} {
        L->right = R;
        R->left = L;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) : cap{capacity} {}
    
    int get(int key) {
        if (loc.find(key) == loc.end()) return -1;
        auto t = loc[key];
        remove(t);
        t->cnt++;
        insert(t);
        updateMinCnt();
        return t->val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        if (get(key) != -1) {
            loc[key]->val = value;
        } else {
            if (cap == loc.size()) popTail();
            auto t = new Node(key, value);
            loc[key] = t;
            min_cnt = 1;
            insert(t);
        }
    }

private:
    bool empty(List *l) const { return l->L->right == l->R; }

    void updateMinCnt() {
        if (empty(list_loc[min_cnt])) ++min_cnt;
    }

    void remove(Node *t) {
        t->left->right = t->right;
        t->right->left = t->left;
    }

    void insert(Node *t) {
        int c = t->cnt;
        if (list_loc.find(c) == list_loc.end()) list_loc[c] = new List(c);
        auto l = list_loc[c];
        t->right = l->L->right;
        l->L->right->left = t;
        t->left = l->L;
        l->L->right = t;
    }

    void popTail() {
        auto t = list_loc[min_cnt]->R->left;
        remove(t);
        loc.erase(t->key);
    }

    unordered_map<int, Node*> loc;
    unordered_map<int, List*> list_loc;
    int min_cnt;
    int cap;
};