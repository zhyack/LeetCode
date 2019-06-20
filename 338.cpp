class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret({0});
        for (int i = 1;i <= num; i++)
            if (i&1) ret.push_back(ret[i>>1]+1);
            else ret.push_back(ret[i>>1]);
        return ret;
    }   
};