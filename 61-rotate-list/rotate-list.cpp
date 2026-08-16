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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int n=0;
       ListNode*temp=head;
        ListNode*end;
       while(temp!=NULL){
        n++;
        end=temp;
        temp=temp->next;
       }
       if(k%n==0)return head;
       ListNode*dummy=new ListNode(0);
       dummy->next=head;

       // cout<<n<<endl;
       int fromStart=n-(k%n);//this is the element i need from the start and break the rest and attach to the start 
      
       ListNode*start;
       temp=head;
       while(fromStart--){
          start=temp;
          temp=temp->next;
       }
         start->next=NULL;
          dummy->next=temp;
          end->next=head;
          return dummy->next;
    }
};