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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ret(0);
        ListNode *p = &ret, *p1=l1, *p2=l2;
        while(p1 || p2){
            if (p1 && p2 && p1->val<p2->val || p1 && !p2){
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        return ret.next;
    }
};