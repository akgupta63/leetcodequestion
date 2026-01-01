class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;

        while (p->next && p->next->next) {
            auto a = p->next;
            auto b = a->next;

            a->next = b->next;
            b->next = a;
            p->next = b;

            p = a;
        }
        return dummy.next;
    }
};
