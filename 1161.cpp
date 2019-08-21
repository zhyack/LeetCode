/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root, int d, unordered_map<int, int> &m){
    m[d]+=root->val;
    if (root->left!=NULL) dfs(root->left, d+1, m);
    if (root->right!=NULL) dfs(root->right, d+1, m);
}
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> m;
        dfs(root, 1, m);
        int ret = 1;
        for (auto it:m) if (it.second>m[ret] || it.second==m[ret] && it.first<ret) ret = it.first;
        return ret;
    }
};