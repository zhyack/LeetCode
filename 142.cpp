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
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* p = head;
        if (p==NULL) return NULL;
        while(p){
            if (s.find(p)!=s.end()) return p;
            s.insert(p);
            p=p->next;
        }
        return NULL;
    }
};