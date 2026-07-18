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
    ListNode* swapPairs(ListNode* head) {

        // add a dummy node
        if(head==NULL || head->next==NULL)return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* endOfLast = dummy;

        while (curr!=NULL && curr->next !=NULL) {
            ListNode* past = NULL;
            ListNode* future ;
            ListNode*store=curr;
            int cnt=2;
            while (cnt--) {
                future= curr->next;
                curr->next = past;
                past = curr;
                curr = future;
            }
            endOfLast->next=past;
            endOfLast=store;
        }
         endOfLast->next = curr;

        return dummy->next;
    }
};