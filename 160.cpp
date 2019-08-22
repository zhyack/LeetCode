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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> s;
        ListNode *p = headA;
        while(p!=NULL){
            s.insert(p);
            p=p->next;
        }
        p = headB;
        while(p!=NULL){
            if (s.find(p)!=s.end()) return p;
            p=p->next;
        }
        return NULL;
    }
};