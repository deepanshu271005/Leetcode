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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(0);
        int size=0;
        ListNode*curr=head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        dummy->next=head;
         curr=dummy;
        ListNode*prev=dummy;
        int k=size-n+1;
        while(k--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return dummy->next;
    }
};