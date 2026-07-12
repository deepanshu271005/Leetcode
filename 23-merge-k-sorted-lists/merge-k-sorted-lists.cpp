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

     struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val; // Creates a Min-Heap based on node values
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        // to track the largest
        ListNode* ans = new ListNode;
        ListNode* temp;
        temp = ans;

        for (auto i : lists) {
            if (i != NULL)
                pq.push(i); // pushing the samllest of all the list to find the
                            // smalllest overall
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top->next != NULL)
                pq.push(top->next);
            int value = top->val;
            ListNode* new_node = new ListNode(value);
            temp->next = new_node;
            temp = temp->next;
        }
        return ans->next;
    }
};