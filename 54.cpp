const int dirs[4][2] = {0,1,1,0,0,-1,-1,0};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int n = matrix.size();
        if (n==0) return ret;
        int m = matrix[0].size();
        if (m==0) return ret;
        int i = 0, j = 0, d = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while(true){
            visited[i][j]=true;
            ret.push_back(matrix[i][j]);
            int x = i+dirs[d][0], y = j+dirs[d][1];
            if (x<0 || y<0 || x>=n || y>=m || visited[x][y]){
                d = (d+1)%4;
                x = i+dirs[d][0], y = j+dirs[d][1];
                if (x<0 || y<0 || x>=n || y>=m || visited[x][y]) break;
            }
            i = x, j = y;
        }
        return ret;
    }
};