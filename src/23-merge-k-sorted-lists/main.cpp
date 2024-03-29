#include "headers/list.h"
#include <queue>
using namespace std;
// https://leetcode.cn/problems/merge-k-sorted-lists/

// O(kn * log(k))
class Solution {
public:
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode dummy, *tail = &dummy;
        for (auto l: lists) if (l) q.push(l);

        while (q.size()) {
            auto t = q.top(); q.pop();
            tail = tail->next = t;
            if (t->next) q.push(t->next);
        }

        return dummy.next;
    }
};