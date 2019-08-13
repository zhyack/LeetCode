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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        queue<TreeNode*> ql, qr;
        ql.push(root->left);
        qr.push(root->right);
        while(!ql.empty() && !qr.empty()){
            TreeNode* qlr = ql.front();
            TreeNode* qrr = qr.front();
            ql.pop();
            qr.pop();
            //cout << qlr->val << "," << qrr->val << endl;
            if (qlr==NULL && qrr==NULL) continue;
            if (qrr==NULL||qlr==NULL || qlr->val!=qrr->val) return false;
            ql.push(qlr->left);
            ql.push(qlr->right);
            qr.push(qrr->right);
            qr.push(qrr->left);
        }
        if (!ql.empty() || !qr.empty()) return false;
        return true;
    }
};