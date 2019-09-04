/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node{
    TreeNode* r;
    int lh, rh, s;
    Node(TreeNode* root, int ll = -1, int rr = -1, int ss = 0){
        r = root;
        lh = ll;
        rh = rr;
        s = ss;
    }
};
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        if (root==NULL) return ret;
        stack<Node> ps;
        int rs;
        ps.push(Node(root));
        while(!ps.empty()){
            Node t = ps.top();
            // cout << t.r->val << endl;
            ps.pop();
            if (t.s==0){
                if (t.r->left!=NULL){
                    ps.push(Node(t.r, -1, -1, 1));
                    ps.push(Node(t.r->left));
                }
                else{
                    ps.push(Node(t.r, 0, -1, 2));
                }
            }
            else if (t.s==1){
                ps.push(Node(t.r, rs, -1, 2));
            }
            else if (t.s==2){
                if (t.r->right!=NULL){
                    ps.push(Node(t.r, t.lh, -1, 3));
                    ps.push(Node(t.r->right));
                }
                else{
                    ps.push(Node(t.r, t.lh, 0, 4));
                }
            }
            else if (t.s==3){
                ps.push(Node(t.r, t.lh, rs, 4));
            }
            else {
                int d = max(t.lh, t.rh)+1;
                if (d>ret.size()) ret.push_back(vector<int>());
                ret[d-1].push_back(t.r->val);
                rs=d;
            }
        }
        return ret;
    }
};