/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool iseq(TreeNode* r1, TreeNode* r2){
    if (r1==NULL && r2==NULL) return true;
    if (r1==NULL && r2) return false;
    if (r1 && r2==NULL) return false;
    if (r1->val != r2->val) return false;
    return true;
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!iseq(p, q)) return false;
        if (p==NULL && q==NULL) return true;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};