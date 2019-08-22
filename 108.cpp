/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* dfs(vector<int>& nums, int l, int r){
    TreeNode* ret = new TreeNode(nums[(l+r+1)/2]);
    if ((l+r+1)/2>l) ret->left = dfs(nums, l, (l+r+1)/2-1);
    if ((l+r+1)/2<r) ret->right = dfs(nums, (l+r+1)/2+1, r);
    return ret;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return NULL;
        return dfs(nums, 0, n-1);
    }
};