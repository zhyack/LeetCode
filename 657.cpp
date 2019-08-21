class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> m;
        m['U'] = make_pair(-1, 0);
        m['D'] = make_pair(1, 0);
        m['L'] = make_pair(0, -1);
        m['R'] = make_pair(0, 1);
        int x=0, y=0;
        for (auto i:moves) x+=m[i].first, y+=m[i].second;
        return (x==0 && y==0);
    }
};