
#include "common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto hair = new ListNode(0), p1 = hair, p2 = head;
        hair->next = head;

        while(p1->next != nullptr && p2->next != nullptr) {
            p1->next = p2->next;
            p2->next = p1->next->next;
            p1->next->next = p2;
            p1 = p2, p2 = p2->next;
        }

        p1 = hair->next;
        delete hair;
        return p1;
    }
};