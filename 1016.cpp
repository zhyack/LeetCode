class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 1;i <= N;i++){
            int k = i;
            string t = "";
            while(k){
                t.push_back(char(k%2+'0'));
                k/=2;
            }
            reverse(t.begin(), t.end());
            if (S.find(t)==-1) return false;
        }
        return true;
    }
};