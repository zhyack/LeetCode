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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s[2];
        vector<vector<int>> ret;
        if (root==NULL) return ret;
        s[0].push(root);
        int depth = -1;
        while(!s[(depth+1)%2].empty()){
            depth++;
            ret.push_back(vector<int>());
            while(!s[depth%2].empty()){
                auto t = s[depth%2].top();
                ret[depth].push_back(t->val);
                s[depth%2].pop();
                if (depth%2==0){
                    if (t->left!=NULL) s[1].push(t->left);
                    if (t->right!=NULL) s[1].push(t->right); 
                }
                else{
                    if (t->right!=NULL) s[0].push(t->right); 
                    if (t->left!=NULL) s[0].push(t->left);
                }
            }
        }
        return ret;
    }
};