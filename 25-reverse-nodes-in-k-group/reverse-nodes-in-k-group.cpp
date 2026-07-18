/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode*chunk_reversing(ListNode*temp,int num_to_rev){

    // }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* temp1 = head;
        while (temp1 != NULL) {
            size++;
            temp1 = temp1->next;
        }
        // cout<<size;

        // first of all in the question in which the head could be altereed
        // better to add a dummy head
        ListNode* temp = new ListNode(0);
        temp->next = head;
        // now my temp is the head
        int chunks = size / k;
        ListNode* ptrOfLastEnd = temp;
        ListNode* curr = head;
        while (chunks--) {
            ListNode* past = NULL;
            ListNode* future = curr->next;
            ListNode* store = curr;

            for (int i = 0; i < k; i++) {
                future = curr->next;
                curr->next = past;
                past = curr;
                curr = future;
            }
            ptrOfLastEnd->next = past;
            ptrOfLastEnd = store;
        }
        ptrOfLastEnd->next = curr;

        return temp->next;
    }
};