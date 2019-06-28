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
    ListNode* swapPairs(ListNode* head) {
        ListNode ret(0);
        ret.next=head;
        ListNode *x=&ret, *y=head;
        while(true){
            if (!y || !y->next) return ret.next;
            ListNode *z=y->next;
            x->next=z;
            y->next=z->next;
            z->next=y;
            y=y->next;
            x=z->next;
        }
        return ret.next;
    }
};