class MagicDictionary {
    unordered_set<string> s;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        s.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        int n = dict.size();
        for (int i = 0;i < n;i++){
            int m = dict[i].length();
            for (int j=0;j<m;j++){
                char k = dict[i][j];
                for (char c='a';c<='z';c++)
                    if (c!=k){
                        dict[i][j]=c;
                        s.insert(dict[i]);
                    }
                dict[i][j]=k;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return s.find(word)!=s.end();
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */