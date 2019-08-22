class WordDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<char, WordDictionary*> d;
    bool is_vocab;
    WordDictionary() {
        d.clear();
        is_vocab=false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* p = this;
        for (char c:word){
            if (p->d.find(c)==p->d.end()) p->d[c]=new WordDictionary();
            p = p->d[c];
        }
        p->is_vocab=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (word.length()==0 && this->is_vocab) return true;
        if (word.length()==0) return false;
        WordDictionary* p = this;
        string next_to_search = word.substr(1);
        if (word[0]=='.'){
            for (auto it:this->d)
                if (it.second->search(next_to_search)) return true;
            return false;
        }
        else if (p->d.find(word[0])!=p->d.end()){
            return this->d[word[0]]->search(next_to_search);
        }
        else return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */