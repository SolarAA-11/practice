
#include "common.h"

class Solution {
private:
    using p_node = ListNode*;
    p_node func(p_node head) {
        p_node p1 = nullptr, p2 = head;
        while (p2 != nullptr) {
            auto tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        head->next = nullptr;
        return p1;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto hair = new ListNode(0), p1 = hair, p2 = hair;
        hair->next = head;
        auto next_k = [=](p_node p) {
            int kk = k;
            while(kk-- && p != nullptr) {
                cout << p->val << " : " << k << endl;
                p = p->next;
            }
            return p;
        };
        p2 = next_k(p2);
        while(p2 != nullptr) {
            auto next_sub_link_head = p2->next;
            p2->next = nullptr;
            auto sub_link_new_head = func(p1->next);
            auto sub_link_new_tail = p1->next;
            p1->next = sub_link_new_head;
            sub_link_new_tail->next = next_sub_link_head;
            p1 = p2 = sub_link_new_tail;
            p2 = next_k(p2);
        }
        p1 = hair->next;
        delete hair;
        return p1;
    }
};

int main() {
    Solution s;
}
