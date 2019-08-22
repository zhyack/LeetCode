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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ret;
        if (root==NULL) return ret;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            auto item = q.front();
            q.pop();
            TreeNode* p=item.first;
            int d = item.second;
            if (d>=ret.size()) ret.push_back(vector<int>());
            ret[d].push_back(p->val);
            if (p->left!=NULL) q.push(make_pair(p->left, d+1));
            if (p->right!=NULL) q.push(make_pair(p->right, d+1));
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};