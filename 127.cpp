class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<int> t(n+1,0);
        wordList.push_back(beginWord);
        queue<int> q;
        q.push(n);
        t[n]=1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            string sx = wordList[x];
            for (int i = 0;i < n+1; i++){
                if (wordList[i].length()!=sx.length()) continue;
                if (i==x) continue;
                if (t[i]>0) continue;
                int cnt = 0;
                for (int j = 0;j < sx.length(); j++){
                    if (sx[j]!=wordList[i][j]) cnt++;
                    if (cnt>1) break;
                }
                if (cnt==1){
                    q.push(i);
                    t[i]=t[x]+1;
                    if (wordList[i]==endWord) return t[i];
                }
            }
        }
        return 0;
        
    }
};