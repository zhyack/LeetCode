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
        int n1 = 0, n2 = 0;
        ListNode *p = l1;
        while(p!=NULL) p=p->next, n1++;
        p = l2;
        while(p!=NULL) p=p->next, n2++;
        if (n1<n2){
            swap(l1, l2);
            swap(n1, n2);
        }
        vector<int> s(n1+2,0);
        int n = 0;
        ListNode *p1 = l1, *p2=l2;
        for (int i = n1;i > 0;i--){
            if (i<=n2){
                s[i] = p1->val+p2->val;
                p2 = p2->next;
            }
            else s[i] = p1->val;
            p1 = p1->next;
        }
        for (int i = 1; i <= n1;i++) 
            if (s[i]>9){
                s[i]=s[i]%10;
                s[i+1]++;
            }
        ListNode *ret = new ListNode(0);
        n = n1;
        p = ret;
        if (s[n1+1]>0) ret->val = s[n1+1];
        else ret->val = s[n1], n--;
        while(n){
            p->next = new ListNode(s[n]);
            p =p->next;
            n--;
        }
        return ret;
    }
};