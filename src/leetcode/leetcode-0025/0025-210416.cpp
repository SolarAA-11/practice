
#include "common.h"

class Solution {
private:
    ListNode* reverseKSegment(ListNode* hair) {
        auto tail = hair->next, p1 = hair, p2 = hair->next;
        while(p2 != nullptr) {
            auto temp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = temp;
        }
        hair->next = p1;
        tail->next = nullptr;
        return tail;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto hair = new ListNode(0), p1 = hair, p2 = hair;
        hair->next = head;
        while(true) {
            for (int i = 0; i < k && p2 != nullptr; ++i)
                p2 = p2->next;
            if (p2 == nullptr) {
                break;
            } else {
                auto temp = p2->next;
                p2->next = nullptr;
                p1 = reverseKSegment(p1);
                p1->next = temp;
                p2 = p1;
            }
        }
        p1 = hair->next;
        delete hair;
        return p1;
    }
};