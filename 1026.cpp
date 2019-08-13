/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> dfs(TreeNode* root){
    vector<int> retl({0, root->val, root->val}), retr({0, root->val, root->val}), ret({0,root->val, root->val});
    if (root->left!=NULL) retl=dfs(root->left);
    if (root->right!=NULL) retr=dfs(root->right);
    ret[0]=max(max(abs(root->val-retl[1]), abs(root->val-retl[2])), max(abs(root->val-retr[1]), abs(root->val-retr[2])));
    ret[0]=max(ret[0], max(retl[0], retr[0]));
    ret[1]=max(root->val, max(retl[1], retr[1]));
    ret[2]=min(root->val, min(retl[2], retr[2]));
    return ret;
}

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root==NULL) return 0;
        vector<int> res=dfs(root);
        return res[0];
    }
};