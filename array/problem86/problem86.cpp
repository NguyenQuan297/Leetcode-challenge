// ListNode is provided by LeetCode's environment.

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* less    = &lessDummy;
        ListNode* greater = &greaterDummy;

        for (ListNode* node = head; node; node = node->next) {
            if (node->val < x) {
                less->next = node;
                less       = less->next;
            } else {
                greater->next = node;
                greater       = greater->next;
            }
        }

        greater->next  = nullptr;              // terminate greater list
        less->next     = greaterDummy.next;    // join the two lists
        return lessDummy.next;
    }
};
