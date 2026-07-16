/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ans = NULL;
        // slow will move one at a time and the fast will move 2 at a time

        while (true) {
            if (fast == NULL || fast->next == NULL)
                return NULL;
            // there is an end to the linked list
            slow = slow->next;
            fast = fast->next->next;
              if (fast == slow) {
                // cycle detected

                ListNode* temp = head;
                while (temp != fast) {
                    temp = temp->next;
                    fast =
                        fast->next; // move both the pointer wiht the same speed
                    // they will meet at the start of the cyle start
                }

                ans = temp;
                return temp;
                break;
            }
        }

        return ans;
    }
};