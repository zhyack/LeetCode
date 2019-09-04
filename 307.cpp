struct Node{
    Node *lson, *rson;
    int left, right, val, lazy; 
    Node(int l, int r, int v, int la=0){
        left = l;
        right = r;
        val = v;
        lazy = la;
        lson = NULL;
        rson = NULL;
    }
    Node(){
    }
};

void buildTree(Node &root){
    if (root.left==root.right) return;
    int mid = (root.left+root.right)/2;
    root.lson = new Node(root.left, mid, 0);
    buildTree(*root.lson);
    root.rson = new Node(mid+1, root.right, 0);
    buildTree(*root.rson);
}

void updateTree(Node &root, int l, int r, int v){
    //cout << l << "," << r << "  :  " << root.left << ", " << root.right << endl;
    root.val+=(r-l+1)*v;
    if (l==root.left && r==root.right){
        root.lazy+=v;
        return;
    }
    int mid = (root.left+root.right)/2;
    updateTree(*root.lson, root.left, mid, root.lazy);
    updateTree(*root.rson, mid+1, root.right, root.lazy);
    root.lazy = 0;
    if (l<=mid) updateTree(*root.lson, l, min(mid,r), v);
    if (r>mid) updateTree(*root.rson, max(l,mid+1), r, v);
}

int queryTree(Node &root, int l, int r){
    if (l==root.left && r==root.right) return root.val;
    int mid = (root.left+root.right)/2;
    updateTree(*root.lson, root.left, mid, root.lazy);
    updateTree(*root.rson, mid+1, root.right, root.lazy);
    root.lazy = 0;
    int ret = 0;
    if (l<=mid) ret += queryTree(*root.lson, l, min(mid,r));
    if (r>mid) ret += queryTree(*root.rson, max(l,mid+1), r);
    return ret;
}

class NumArray {
public:
    Node root;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = Node(0,n-1,0,0);
        if (n) buildTree(root);
        for (int i = 0;i < n;i++) updateTree(root, i, i, nums[i]);
    }
    
    void update(int i, int val) {
        int origin_val = queryTree(root, i, i);
        updateTree(root, i, i, val-origin_val);
    }
    
    int sumRange(int i, int j) {
        return queryTree(root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */