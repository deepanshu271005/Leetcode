class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
          

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* future = curr->next;
            curr->next = future->next;
            future->next = prev->next;
            prev->next = future;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};