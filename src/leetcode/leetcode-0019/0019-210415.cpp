
#include "common.h"


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) return nullptr;
        auto p1 = head, p2 = head, hair = new ListNode(0);
        auto pre_p1 = hair;
        hair->next = head;
        for (int i = 0; i < n; ++i)  p2 = p2->next;
        while(p2 != nullptr) {
            p2 = p2->next;
            pre_p1 = p1;
            p1 = p1->next;
        }
        pre_p1->next = p1->next;
        delete p1;

        auto ans = hair->next;
        delete hair;

        return ans;
    }
};

