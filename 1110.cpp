/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool dfs(TreeNode* root, unordered_set<int> &td, vector<TreeNode*> &ret, bool is_root){
    if (is_root && td.find(root->val)==td.end()) ret.push_back(root);
    bool next_root=false;
    if (td.find(root->val)!=td.end()) next_root=true;
    if (root->left) 
        if (dfs(root->left, td, ret, next_root)) 
            root->left=NULL;
    if (root->right) 
        if (dfs(root->right, td, ret, next_root))
            root->right=NULL;
    return next_root;
}

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> td;
        for (int d:to_delete) td.insert(d);
        vector<TreeNode*> ret;
        if (root)
            dfs(root, td, ret, true);
        return ret;
    }
};