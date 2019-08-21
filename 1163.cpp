class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        unordered_map<int, int> m, e;
        set<int> current_parents;
        char c='a';
        for (int i = 0;i < n;i++){
            if (s[i]>c){
                current_parents.clear();
                current_parents.insert(i);
                c = s[i];
            }
            else if (s[i]==c) current_parents.insert(i);
            m[i] = i;
            e[i] = i;
        }
        while(current_parents.size()>1){
            // for (auto i:current_parents) cout << i << ", ";
            // cout << endl;
            c = 'a';
            set<int> np;
            for (set<int>::reverse_iterator it = current_parents.rbegin(); it!=current_parents.rend(); it++){
                int i = *it;
                m[i+1]=m[i];
                e[m[i+1]]=i+1;
                // cout << i << "," << m[i+1] << "," << e[m[i+1]] << endl;
                if (i<n){
                    if (s[i+1]>c){
                        np.clear();
                        np.insert(i+1);
                        c = s[i+1];
                    }
                    else if (s[i+1]==c) np.insert(i+1); 
                }
            }
            // for (auto i:np) cout << i << ", ";
            // cout << endl;
            // for (auto i:np) cout << e[i] << ", ";
            // cout << endl;
            current_parents = np;
            for (int i:np){
                if (current_parents.find(i)==current_parents.end()) continue;
                int k = i;
                while(k<n && k!=e[k] && current_parents.find(e[k])!=current_parents.end()){
                    k = e[k];
                    current_parents.erase(k);
                }
            }
            
            
        }
        return s.substr(m[*(current_parents.begin())]);
        
        
    }
};