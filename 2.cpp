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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1, *q=l2, *r=new ListNode(0), *rh;
        int c=0;
        rh = r;
        while(p||q||c){
            if (p && !q) r->val = p->val+c;
            else if (!p && q) r->val = q->val+c;
            else if (p && q) r->val = p->val+q->val+c;
            else r->val=c;
            c = r->val/10;
            r->val = r->val%10;
            if (p) p=p->next;
            if (q) q=q->next;
            if (p||q||c) {
                r->next = new ListNode(0);
                r = r->next;
            }
        }
        return rh;
    }
};