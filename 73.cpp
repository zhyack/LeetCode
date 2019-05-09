class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0) return;
        int m = matrix[0].size();
        bool fr=false;
        int i, j;
        for (i = 0;i < n; i++)
            for (j=0; j<m;j++)
                if (matrix[i][j]==0){
                    if (i==0) fr=true;
                    else matrix[i][0]=0;
                    matrix[0][j]=0;
                }
        for (i = 1;i<n;i++)
            for (j=1;j<m;j++)
                if (matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
        if (matrix[0][0]==0)
            for (i=0;i < n;i++) matrix[i][0]=0;
        if (fr)
            for (j=0;j<m;j++) matrix[0][j]=0;
    }
};