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
    bool isUnivalTree(TreeNode* root) {
        bool ret=true;
        if (root->left) ret=ret && isUnivalTree(root->left) && root->val==root->left->val;
        if (ret && root->right) ret = ret && isUnivalTree(root->right) && root->val==root->right->val;
        return ret;
    }
};