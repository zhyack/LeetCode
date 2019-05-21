/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* flattenWithLast(TreeNode* root){
        TreeNode* ret = root;
        if (root->left) ret = flattenWithLast(root->left);
        if (root->right){
            ret->right=root->right;
            ret = flattenWithLast(root->right);
        }
        if (root->left){
            root->right=root->left;
            root->left=NULL;
        }
        return ret;
    }
    void flatten(TreeNode* root) {
        if (root) flattenWithLast(root);
    }
};