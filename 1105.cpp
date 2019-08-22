class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        if (n==1) return books[0][1];
        vector<vector<int>> dp(n, vector<int>(shelf_width+1, -1));
        int min_last=0;
        for (int i = 0;i < n;i++){
            int ws = 0, mh = 0;
            dp[i][books[i][0]]=min_last+books[i][1];
            min_last = dp[i][books[i][0]];
            for (int j = i-1;j >=0; j--){
                ws+=books[j][0];
                mh=max(mh, books[j][1]);
                if (ws+books[i][0]>shelf_width) break;
                dp[i][ws+books[i][0]]=dp[i-1][ws]-mh+max(mh,books[i][1]);
                min_last = min(dp[i][ws+books[i][0]], min_last);
            }
        }
        return min_last;
    }
};