class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret(0);
        int n = words.size();
        if (n==1) return ret;
        vector<vector<int>> prefixes(n), suffixes(n), prepalins(n), sufpalins(n);
        unordered_map<int, int> forward_whole, backward_whole;
        int MOD = 1e9+7;
        for (int i = 0;i < n;i ++){

            int m = words[i].length();
            long long hash = 0;
            prefixes[i] = vector<int>(m+1, 0);
            for (int j = 0; j < m;j++){
                hash = (hash*30+(words[i][j]-'a'+1))%MOD;
                prefixes[i][j+1] = hash;
            }
            forward_whole[hash]=i;
            
            hash = 0;
            suffixes[i] = vector<int>(m+1, 0);
            for (int j = m-1; j >=0;j--){
                hash = (hash*30+(words[i][j]-'a'+1))%MOD;
                suffixes[i][j] = hash;
            }
            backward_whole[hash]=i;
            
            
            prepalins[i] = vector<int>(m+1, -1);
            long long low_mult=1, high_mult=1;
            long long forward_hash=0, backward_hash=0;
            for (int j = 0; j < m;j++){
                if (j>0){
                    if (j&1){
                        backward_hash=(backward_hash+(words[i][j]-'a'+1)*high_mult%MOD)%MOD;
                        high_mult = high_mult*30%MOD;
                    }
                    else{
                        backward_hash=(backward_hash-(words[i][j/2]-'a'+1)*low_mult%MOD+MOD+(words[i][j]-'a'+1)*high_mult%MOD)%MOD;
                        low_mult = low_mult*30%MOD;
                        high_mult = high_mult*30%MOD;
                    }
                    forward_hash=prefixes[i][(j-1)/2+1]*low_mult%MOD;
                }
                if (forward_hash==backward_hash) 
                    prepalins[i][j+1] = suffixes[i][j+1];
            }
            prepalins[i][0]=suffixes[i][0];
            
            
            
            sufpalins[i] = vector<int>(m+1, -1);
            low_mult=1, high_mult=1;
            forward_hash=0, backward_hash=0;
            for (int j = m-1; j >= 0;j--){
                if (j<m-1){
                    if ((m-j)&1){
                        forward_hash=(forward_hash-(words[i][m-(m-j)/2-1]-'a'+1)*low_mult%MOD+MOD+(words[i][j]-'a'+1)*high_mult%MOD)%MOD;
                        low_mult = low_mult*30%MOD;
                        high_mult = high_mult*30%MOD;
                    }
                    else{
                        forward_hash=(forward_hash+(words[i][j]-'a'+1)*high_mult%MOD)%MOD;
                        high_mult = high_mult*30%MOD;
                    }
                    backward_hash=suffixes[i][m-(m-j)/2]*low_mult%MOD;
                }
                if (forward_hash==backward_hash) 
                    sufpalins[i][j] = prefixes[i][j];
            }
            sufpalins[i][m]=prefixes[i][m];
            
        }
        
        vector<unordered_set<int>> ans(n);
        
        for (int i = 0;i < n; i++){
            int m = words[i].length();
            for (int j = 0;j <= m;j++){
                if (prepalins[i][j]>=0 && forward_whole.find(prepalins[i][j])!=forward_whole.end()){
                    int k = forward_whole[prepalins[i][j]];
                    if (i!=k && ans[k].find(i)==ans[k].end()){
                        ret.push_back(vector<int>({k, i}));
                        ans[k].insert(i);
                    }
                }
                if (sufpalins[i][j]>=0 && backward_whole.find(sufpalins[i][j])!=backward_whole.end()){
                    int k = backward_whole[sufpalins[i][j]];
                    if (i!=k && ans[i].find(k)==ans[i].end()){
                        ret.push_back(vector<int>({i, k}));
                        ans[i].insert(k);
                    }
                }
            }
        }
        
        return ret;
        
    }
};