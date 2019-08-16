/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

pair<TreeNode*, int> dfs(TreeNode* root, int d){
    pair<TreeNode*, int> retl=make_pair(root, d), retr=make_pair(root, d);
    if (root->left!=NULL) retl = dfs(root->left, d+1);
    if (root->right!=NULL) retr = dfs(root->right, d+1);
    // cout << root->val << ":" << retl.second << "," << retr.second << endl;
    if (retl.second>retr.second) return retl;
    else if (retr.second>retl.second) return retr;
    else return make_pair(root, retl.second);
}
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root==NULL) return root;
        return dfs(root, 0).first;
    }
};