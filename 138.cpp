/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        unordered_map<int, Node*> mn;
        mn.clear();
        Node* p = head;
        while(p){
            mn[p->val]=new Node();
            mn[p->val]->val=p->val;
            mn[p->val]->next=NULL;
            mn[p->val]->random=NULL;
            p = p->next;
        }
        p = head;
        while(p){
            if (p->next) mn[p->val]->next=mn[p->next->val];
            if (p->random) mn[p->val]->random=mn[p->random->val];
            p = p->next;
        }
        return mn[head->val];
    }
};