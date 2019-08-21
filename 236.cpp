/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int top(int x, unordered_map<int, int>& f){
    if (f.find(x)==f.end()) f[x]=x;
    else if (f[x]!=x) f[x] = top(f[x], f);
    return f[x];
}

void do_union(unordered_map<int, int>& f, int x, int y){
    int fx = top(x, f);
    int fy = top(y, f);
    if (fx!=fy) f[fy]=fx;
}

void dfs(TreeNode* root, TreeNode* p, TreeNode* q, unordered_map<int, int>& f, TreeNode* &r, bool &b){
    if (root->left!=NULL){
        dfs(root->left, p, q, f, r, b);
        if (b) return;
        do_union(f, root->val, root->left->val);
        if (top(p->val, f)==top(q->val, f)){
            b=true;
            r=root;
            return;
        }
    }
    if (root->right!=NULL){
        dfs(root->right, p, q, f, r, b);
        if (b) return;
        do_union(f, root->val, root->right->val);
        if (top(p->val, f)==top(q->val, f)){
            b=true;
            r=root;
            return;
        }
    }    
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, int> m;
        TreeNode* ret=root;
        bool find=false;
        dfs(root, p, q, m, ret, find);
        return ret;
    }
};