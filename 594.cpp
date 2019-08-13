class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        unordered_map<int,int> m;
        for (auto i:nums){
            if (m.find(i)==m.end()) m[i]=0;
            m[i]++;
        }
        int ret = 0;
        for (auto i:m){
            if (m.find(i.first-1)!=m.end()) ret=max(ret, m[i.first-1]+i.second);
            if (m.find(i.first+1)!=m.end()) ret=max(ret, m[i.first+1]+i.second);
        }
        return ret;
    }
};