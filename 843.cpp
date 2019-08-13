/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        vector<vector<int>> sim(n, vector<int>(n));
        vector<vector<int>> cnt(n, vector<int>(7, 0));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++){
                sim[i][j]=0;
                for (int k = 0;k < 6;k++)
                    if (wordlist[i][k]==wordlist[j][k])
                        sim[i][j]++;
                cnt[i][sim[i][j]]++;
            }
        vector<bool> valid(n, true);
        while(true){
            int choose_id = 0, max_val=n+1;
            for (int i = 0;i < n;i++){
                int mm = 0;
                for (int k = 0;k <= 6;k++) mm = max(mm, cnt[i][k]);
                if (mm<max_val){
                    choose_id = i;
                    max_val=mm;
                }
            }
            
            int ans = master.guess(wordlist[choose_id]);
            
            if (cnt[choose_id][ans]==1){
                for (int i = 0;i < n;i++)
                    if (valid[i] && sim[choose_id][i]==ans) master.guess(wordlist[i]);
                break;
            }
            for (int i = 0;i < n;i++)
                if (valid[i] && sim[choose_id][i]!=ans) valid[i]=false;
            for (int i = 0;i < n;i++){
                for (int k = 0;k <= 6;k++) cnt[i][k]=0;
                for (int j = 0;j < n;j++)
                    if (valid[j])
                        cnt[i][sim[i][j]]++;
            }
        }
    }
};