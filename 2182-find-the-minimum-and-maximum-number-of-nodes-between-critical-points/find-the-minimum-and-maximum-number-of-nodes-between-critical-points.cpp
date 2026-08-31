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
        vector<int>nodes;
        ListNode*curr1=head;
        while(curr1!=NULL){
            nodes.push_back(curr1->val);
            curr1=curr1->next;
        }

       if(nodes.size()==2)return {-1,-1};
       int pre=0;
       int curr=1;
       int next=2;
       vector<int>critical;
       while(next<nodes.size()){
        if (nodes[curr]<nodes[pre]&& nodes[curr]<nodes[next]){
            critical.push_back(curr);
        }
        else if (nodes[curr]>nodes[pre]&& nodes[curr]>nodes[next]){
            critical.push_back(curr);
        }
        pre++;
        curr++;
        next++;
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