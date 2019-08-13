struct Node{
    int x, c;
};
bool operator <(const Node &A, const Node &B){
    return A.c>B.c;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (auto i:nums){
            if (m.find(i)==m.end()) m[i]=0;
            m[i]++;
        }
        int n = 0;
        vector<Node> a(m.size());
        for (auto i:m){
            a[n].x=i.first;
            a[n].c=i.second;
            n++;
        }
        nth_element(a.begin(), a.begin()+k, a.end());
        vector<int> ret(0);
        for (int i = 0; i < k;i++) ret.push_back(a[i].x);
        return ret;
        
    }
};