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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // vector<int>nodes;
    //     ListNode*curr1=head;
    //     int cnt=0;
    //     while(curr1!=NULL){
    //         // nodes.push_back(curr1->val);
    //         // curr1=curr1->next;
    //         cnt++;
    //         curr1=curr1->next;
    //     }

    //    if(cnt==2)return {-1,-1};
       ListNode* pre=head;
       ListNode *curr=head->next;
       ListNode* next=head->next->next;
       int idx=1;
       if(next==NULL)return {-1,-1};
       vector<int>critical;
       while(next!=NULL){
        if ( curr->val > pre->val && curr->val > next->val ){
            critical.push_back(idx);
        }
        else if (curr->val < pre->val && curr->val < next->val){
            critical.push_back(idx);
        }
        pre=pre->next;
        curr=curr->next;
        next=next->next;
        idx++;
       }
 
      if(critical.size()<2){
        return {-1,-1};
      }
      int max_dist=critical.back()-critical[0];
      int min_dist=INT_MAX;
      for(int i=1;i<critical.size();i++){
          min_dist=min(min_dist,critical[i]-critical[i-1]);
      }
       
        return {min_dist,max_dist};

    }
};