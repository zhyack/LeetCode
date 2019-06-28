/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Node{
    ListNode *p;
    Node(ListNode *x): p(x){};
};
bool operator <(const Node A, Node B){
    return A.p->val>B.p->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        ListNode ret(0);
        ListNode *p=&ret;
        int n = lists.size();
        for (int i = 0;i < n;i++) if (lists[i]) q.push(*(new Node(lists[i])));
        while(!q.empty()){
            ListNode* t = q.top().p;
            q.pop();
            p->next=t;
            if (t->next) q.push(*(new Node(t->next)));
            p=p->next;
        }
        return ret.next;
    
    }
};