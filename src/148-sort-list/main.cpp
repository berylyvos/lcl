#include <cstdio>
#include <vector>
#include "headers/list.h"

using namespace std;

class Solution {
public:
    ListNode* mergeSortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) ++ n;
        auto dummy = new ListNode(-1);
        dummy->next = head;

        for (int sz = 1; sz < n; sz *= 2) { // 归并区间大小：1, 2, 4, ..., x (x<n)
            auto cur = dummy;

            // i + sz <= n：保证要归并的左区间存在
            for (int i = 0; i + sz <= n; i += sz * 2) {
                auto left = cur->next, right = left;
                for (int j = 0; j < sz; ++ j) right = right->next;

                // 归并两个有序链表 left, right
                int x = 0, y = 0;
                while (x < sz && y < sz && right) {
                    if (left->val <= right->val) cur = cur->next = left, left = left->next, ++ x;
                    else cur = cur->next = right, right = right->next, ++ y;
                }
                while (x < sz) cur = cur->next = left, left = left->next, ++ x;
                while (y < sz && right) cur = cur->next = right, right = right->next, ++ y;

                // 连接下一段
                cur->next = right; 
            }
        }
        return dummy->next;
    }

    static ListNode* getTail(ListNode *head) {
        while (head->next) head = head->next;
        return head;
    }

    ListNode* quickSortList(ListNode* head) {
        if (!head || !head->next) return head;

        auto lhead = new ListNode(-1), mhead = new ListNode(-1), rhead = new ListNode(-1);
        auto left = lhead, mid = mhead, right = rhead;

        int x = head->val;
        for (auto p = head; p; p = p->next) {
            if (p->val < x) left = left->next = p;
            else if (p->val > x) right = right->next = p;
            else mid = mid->next = p;
        }

        left->next = mid->next = right->next = nullptr;

        lhead->next = quickSortList(lhead->next);
        rhead->next = quickSortList(rhead->next);

        getTail(lhead)->next = mhead->next;
        getTail(mhead)->next = rhead->next;

        return lhead->next;
    }

    ListNode* sortList(ListNode* head) {
        return mergeSortList(head);
        // return quickSortList(head);
    }
};

int main()
{
    int n;
    printf("input n: ");
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++ i) scanf("%d", &arr[i]);

    auto head = Solution().sortList(vec2list(arr));
    print_list(head);
    delete_list(head);
    return 0;
}