//
// Created by Shingo Gnix on 2023/3/7.
//
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

// * SOLUTION 2 *
// STL std::list
class LRUCache {
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> cache_loc;
    int capacity_;

public:
    explicit LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (cache_loc.find(key) == cache_loc.end()) {
            return -1;
        }
        cache.splice(cache.cbegin(), cache, cache_loc[key]);
        return cache.cbegin()->second;
    }

    void put(int key, int value) {
        if (cache_loc.find(key) == cache_loc.end()) {
            if (cache_loc.size() == capacity_) {
                cache_loc.erase(cache.back().first);
                cache.pop_back();
            }
            cache.emplace_front(key, value);
            cache_loc[key] = cache.begin();
        } else {
            if (get(key) != value) {
                cache_loc[key]->second = value;
            }
        }
    }
};


// * SOLUTION 1 *
// raw double-linkedlist

struct Node {
    int key, val;
    Node *left, *right;
    Node (int key_, int val_) : key(key_), val(val_), left(nullptr), right(nullptr) {}
};

class LRUCache1 {
private:
    Node *L, *R;
    int capacity_;
    unordered_map<int, Node*> cache;

    void insertToHead(Node *node) {
        node->right = L->right;
        L->right->left = node;
        L->right = node;
        node->left = L;
    }

    void remove(Node *node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }

    void moveToHead(Node *node) {
        remove(node);
        insertToHead(node);
    }

public:
    LRUCache1(int capacity) {
        capacity_ = capacity;
        L = new Node(0, 0), R = new Node(0, 0);
        L->right = R;
        R->left = L;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        auto p = cache[key];
        moveToHead(p);
        return p->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            auto p = cache[key];
            p->val = value;
            moveToHead(p);
        } else {
            if (cache.size() == capacity_) {
                auto p = R->left;
                remove(p);
                cache.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            cache[key] = p;
            insertToHead(p);
        }
    }
};