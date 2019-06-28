/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode* p, bool isleft, TreeNode* c, int presum, int limit){
    int maxsum = presum+c->val;
    if (c->left || c->right) maxsum = -1e9;
    if (c->left) maxsum = max(maxsum, dfs(c, true, c->left, presum+c->val, limit));
    if (c->right) maxsum = max(maxsum, dfs(c, false, c->right, presum+c->val, limit));
    
    if (maxsum<limit){
        if (isleft) p->left=NULL;
        else p->right=NULL;
    }
    return maxsum;
}

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) return root;
        TreeNode ret(0);
        ret.right=root;
        dfs(&ret, false, root, 0, limit);
        return ret.right;
    }
};