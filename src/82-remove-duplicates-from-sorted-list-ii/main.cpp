#include "headers/list.h"
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        auto pre = new ListNode(0x1111, head);
        auto dummy = new ListNode(0, nullptr), cur = dummy;
        for (auto p = head; p; p = p->next, pre = pre->next)
            if (p->val != pre->val && (!p->next || p->next->val != p->val)) {
                cur = cur->next = p;
            }
        
        cur->next = nullptr;
        return dummy->next;
    }
};