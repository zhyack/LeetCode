class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> d(n, 0);
        for (int i = 0;i < n;i++)
            if (dominoes[i]=='L' || dominoes[i]=='R') q.push(i);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if (dominoes[i]=='.') continue;
            if (dominoes[i]=='L' && i>0){
                if (dominoes[i-1]=='R' && d[i-1]==d[i]+1)
                    dominoes[i-1]='.';
                else if (dominoes[i-1]=='.'){
                    dominoes[i-1]='L';
                    q.push(i-1);
                    d[i-1]=d[i]+1;
                }
            }
            if (dominoes[i]=='R' && i<n-1){
                if (dominoes[i+1]=='R' && d[i+1]==d[i]+1)
                    dominoes[i+1]='.';
                else if (dominoes[i+1]=='.'){
                    dominoes[i+1]='R';
                    q.push(i+1);
                    d[i+1]=d[i]+1;
                }
            }
        }
        return dominoes;
    }
};