class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> m;
        for (auto w:words){
            int hash = 0, cnt = 0;
            for (auto c:w){
                if ((hash&(1<<(c-'a')))==0){
                    hash+=1<<(c-'a');
                    cnt++;
                }
            }
            if (cnt<=7) m[hash]++;
        }
        vector<int> ret;
        for (auto w:puzzles){
            int base = 1<<(w[0]-'a'), res = 0;
            unordered_set<int> s;
            for (int i = 1;i < 7;i++) s.insert(w[i]-'a');
            if (s.find(w[0]-'a')!=s.end()) s.erase(w[0]-'a');
            unordered_set<int> can, tmp;
            can.insert(base);
            res+=m[base];
            for (int i:s){
                tmp.clear();
                for (int h:can)
                    tmp.insert((h+(1<<i)));
                for (int h:tmp) can.insert(h), res+=m[h];
            }
            ret.push_back(res);
        }
        return ret;
    }
};