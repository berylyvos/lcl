#include <cstdio>
#include <vector>
#include "headers/list.h"

using namespace std;

ListNode* vec2list(const vector<int>& v) {
    auto head = new ListNode(v[0]), cur = head;
    for (int i = 1; i < (int)v.size(); ++ i) { 
        cur = cur->next = new ListNode(v[i]);
    }
    return head;
}

void print_list(ListNode *head) {
    for (auto p = head; p; p = p->next) printf("%d ", p->val);
    printf("\n");
}

void delete_list(ListNode *head) {
    auto p = head;
    while (p) {
        auto node = p;
        p = p->next;
        delete node;
    }
}
