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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!iseq(root1, root2)) return false;
        if (root1==NULL && root2==NULL) return true;
        if (iseq(root1->left,root2->left) && iseq(root1->right,root2->right))
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        if (iseq(root1->left,root2->right) && iseq(root1->right,root2->left))
            return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return false;
    }
};