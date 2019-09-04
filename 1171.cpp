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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head==NULL) return head;
        bool find = true;
        ListNode superhead(0);
        superhead.next=head;
        unordered_map<int, int> m;
        while(find){
            ListNode* p = &superhead;
            int sum = 0, cnt = 0;
            find = false;
            m.clear();
            while(p){
                sum+=p->val;
                if (m.find(sum)!=m.end()){
                    find = true;
                    break;
                }
                m[sum]=cnt++;
                p=p->next;
            }
            if (find){
                ListNode *q = &superhead;
                int qcnt = 0;
                while(q){
                    if (qcnt==m[sum]){
                        q->next=p->next;
                        break;
                    }
                    q = q->next;
                    qcnt++;
                }
            }
        }
        return superhead.next;
    }
};