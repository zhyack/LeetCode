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
    int countNodes(TreeNode* root) {
        queue<TreeNode*>q;
        int ret = 0;
        if (root){
            ret++;
            q.push(root);
        }
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if (p->left) ret++, q.push(p->left);
            if (p->right) ret++, q.push(p->right);
        }
        return ret;
    }
};