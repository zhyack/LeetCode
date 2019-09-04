bool find(vector<vector<int>>& matrix, int& target, int row_l, int row_r, int col_l, int col_r){
    // cout << row_l << "," << row_r << " -> " << col_l << "," << col_r << endl;
    if (row_l>row_r || col_l > col_r || row_l<0 || col_l<0 || row_r>=matrix.size() || col_r>=matrix[0].size()) return false;
    int row_m = (row_l+row_r)/2;
    int l = col_l, r = col_r;
    while(l<r){
        int m = (l+r+1)/2;
        if (matrix[row_m][m]==target) return true;
        else if (matrix[row_m][m]<target) l=m;
        else r = m-1;
    }
    if (matrix[row_m][l]==target) return true;
    if (matrix[row_m][l]>target) l--;
    return find(matrix, target, row_m+1, row_r, col_l, l) || find(matrix, target, row_l, row_m-1, l+1, col_r);
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        if (m==0) return false;
        return find(matrix, target, 0,n-1, 0,m-1);
    }
};