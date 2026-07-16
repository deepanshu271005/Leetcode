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
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
         ListNode*prev=head;
         ListNode*middle=NULL;
        while(true){
                  if(fast==NULL)break;
                  if(fast->next==NULL){
                     break;
                  }
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"bhar aya ";
        middle=slow;
        prev->next=NULL;
        prev=NULL;
        // reverse or split the linked list in half like from the middle move the slow to reverse the rest of the list 
        
        ListNode*forward=NULL;
        
        while(slow->next!=NULL){
          forward=slow->next;
          slow->next=prev;
          prev=slow;
          slow=forward;
        }

          cout<<"bhar aya ";
         
          slow->next=prev;
           
          // to connect the last link 
          
          ListNode*temp=head;
          while(slow!=NULL && temp!=NULL){
            if(slow==NULL)return false;
            if(temp==NULL)return false;
            if(temp->val!=slow->val){
                     return false;
            }
            temp=temp->next;
            slow=slow->next;
          }
        cout<<"bhar aya ";
     
        return true;

    }
};