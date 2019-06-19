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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode* ret = root;
        while(ret){
            if (ret->val<L) ret=ret->right;
            else if (ret->val>R) ret=ret->left;
            else break;
        }
        if (ret) ret->left=trimBST(ret->left, L, R);
        if (ret) ret->right=trimBST(ret->right, L, R);
        return ret;
    }
};