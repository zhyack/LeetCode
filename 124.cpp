/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> dfs(TreeNode* root, int &ans){
    vector<int> l({int(-1e9),0}),r({int(-1e9),0});
    if (root->left) l = dfs(root->left, ans);
    if (root->right) r = dfs(root->right, ans);
    ans = max(ans, max(l[0], r[0]));
    return vector<int>({root->val+max(0,l[1])+max(0,r[1]), root->val+max(0, max(l[1], r[1]))});
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root==NULL) return 0;
        int ans = -1e9;
        vector<int> ret = dfs(root, ans);
        return max(ans, ret[0]);
    }
};