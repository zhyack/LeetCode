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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> q;
        ListNode* lead = new ListNode(0);
        lead->next=head;
        q.push(lead);
        ListNode* p = head;
        while(p){
            q.push(p);
            if (q.size()>n+1) q.pop();
            p = p->next;
        }
        if (q.size()!=n+1) return head;
        p = q.front();
        p->next = p->next->next;
        return lead->next;
    }
};