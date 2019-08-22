class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size()<=1) return true;
        map<int, int> m;
        for (auto i:intervals){
            if (m.find(i[0])!=m.end()) return false;
            m[i[0]]=i[1];
        }
        map<int, int>::iterator it1, it2;
        it1 = m.begin();
        it2 = it1;
        it2++;
        while(it2!=m.end()){
            if (it2->first<it1->second) return false;
            it1++;
            it2++;
        }
        return true;
    }
};