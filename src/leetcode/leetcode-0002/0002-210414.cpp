//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto pl1 = l1, pl2 = l2;
        while (pl1 != nullptr && pl2 != nullptr)
            pl1 = pl1->next, pl2 = pl2->next;
        if (pl1 == nullptr)
            swap(l1, l2);
        pl1 = l1, pl2 = l2;

        auto pre_l1_node = l1;
        bool plus_one = false;
        while(pl1 != nullptr) {
            pl1->val = pl1->val + (pl2 ? pl2->val : 0) + (plus_one ? 1 : 0);

            plus_one = false;
            if (pl1->val >= 10)
                plus_one = true, pl1->val -= 10;

            pre_l1_node = pl1;
            pl1 = pl1->next, pl2 = pl2 ? pl2->next : nullptr;
        }

        if (plus_one)
            pre_l1_node->next = new ListNode(1);

        return l1;
    }
};

int main() {

}