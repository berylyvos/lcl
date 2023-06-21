// https://leetcode.cn/problems/design-skiplist
#include <vector>
using namespace std;

constexpr int MAX_LV = 16;

struct Node {
    int val;
    vector<Node*> next;
    Node(int val_, int lv_ = MAX_LV) : val(val_), next(lv_, nullptr) {}
};

class Skiplist {
public:
    Skiplist() {
        head = new Node(-1);
    }
    ~Skiplist() {
        delete head;
    }

    void find(int target, vector<Node*> &pre) {
        auto p = head;
        for (int i = lv - 1; i >= 0; --i) {
            while (p->next[i] && p->next[i]->val < target) p = p->next[i];
            pre[i] = p;
        }
    }
    
    bool search(int target) {
        vector<Node*> pre(lv);
        find(target, pre);
        return pre[0]->next[0] && pre[0]->next[0]->val == target;
    }
    
    void add(int num) {
        int level = randomLevel();
        auto node = new Node(num, level);
        lv = max(lv, level);
        vector<Node*> pre(lv, nullptr);
        find(num, pre);
        for (int i = 0; i < level; ++i) {
            node->next[i] = pre[i]->next[i];
            pre[i]->next[i] = node;
        }
    }
    
    bool erase(int num) {
        vector<Node*> pre(lv, nullptr);
        find(num, pre);

        auto node = pre[0]->next[0];
        if (!node || node->val != num) return false;

        for (int i = 0; i < lv; ++i)
            if (pre[i]->next[i] == node)
                pre[i]->next[i] = node->next[i];
        
        delete node;

        while (lv > 1 && head->next[lv - 1] == nullptr) --lv;
        return true;
    }

private:
    Node *head;
    int lv;

    int randomLevel() {
        int level = 1;
        while (rand() % 2 && level < MAX_LV) ++level;
        return level;
    }
};