// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n==0) return -1;
        unordered_set<int> s;
        unordered_map<int, int> from;
        unordered_map<int, unordered_set<int>> to;
        int ceb = 0;
        from[0]=-1;
        for (int i = 1;i < n;i++) s.insert(i);
        while(s.size()>0){
            int k = *(s.begin());
            s.erase(k);
            if (knows(ceb, k)){
                from[k]=ceb;
                ceb=k;
            }
            else{
                to[ceb].insert(k);
            }
        }
        for (int i = 0;i < n;i++){
            if (i!=from[ceb] && i!=ceb){
                if (!knows(i, ceb)) return -1;
            }
            if (i!=ceb && to[ceb].find(i)==to[ceb].end()){
                if (knows(ceb, i)) return -1;
            }
        }
        return ceb;
    }
};