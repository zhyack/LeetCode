class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> m(N, vector<int>(N,1)), up(N, vector<int>(N,0)), down(N, vector<int>(N,0)), left(N, vector<int>(N,0)), right(N, vector<int>(N,0));
        for (auto i:mines) m[i[0]][i[1]]=0;
        int cnt;
        
        for (int i = 0;i < N;i++){
            cnt = 0;
            for (int j = 0;j < N;j++){
                if (m[i][j]) cnt++;
                else cnt=0;
                up[i][j]=cnt;
            }
        }
        
        for (int i = 0;i < N;i++){
            cnt = 0;
            for (int j = N-1;j >=0;j--){
                if (m[i][j]) cnt++;
                else cnt=0;
                down[i][j]=cnt;
            }
        }
        
        for (int j = 0;j < N;j++){
            cnt = 0;
            for (int i = 0;i < N;i++){
                if (m[i][j]) cnt++;
                else cnt=0;
                left[i][j]=cnt;
            }
        }
        
        for (int j = 0;j < N;j++){
            cnt = 0;
            for (int i = N-1;i >=0;i--){
                if (m[i][j]) cnt++;
                else cnt=0;
                right[i][j]=cnt;
            }
        }
    
        int ret = 0;
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++)
                if (m[i][j])
                    ret = max(ret, min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])));
        return ret;
    }
};