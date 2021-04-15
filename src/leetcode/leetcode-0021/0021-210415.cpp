
#include "common.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) swap(l1, l2);
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else return l1 != nullptr ? l1 : l2;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        auto hair = new ListNode(0), p = hair;
        while(l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) swap(l1, l2);
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        p->next = l2;
        p = hair->next;
        delete hair;
        return p;
    }
};