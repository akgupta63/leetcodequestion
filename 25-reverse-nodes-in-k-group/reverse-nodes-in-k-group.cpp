class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (true) {
            // Find the k-th node
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (!kth) break;

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            // Reverse k nodes
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Reconnect
            ListNode* tmp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = tmp;
        }

        return dummy.next;
    }
};
