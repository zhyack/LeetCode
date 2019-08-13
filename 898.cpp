class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s, rs;
        for (auto i:A){
            unordered_set<int> st;
            st.insert(i);
            rs.insert(i);
            for (auto j:s) st.insert(i|j), rs.insert(i|j);
            s=st;
        }
        return rs.size();
    }
};