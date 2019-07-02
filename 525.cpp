class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), ret=0, cnt=0;
        unordered_map<int, int> ed;
        ed[0]=-1;
        for (int i = 0;i < n;i++){
            if (nums[i]) cnt++;
            else cnt--;
            if (ed.find(cnt)==ed.end()) ed[cnt]=i;
            else ret = max(ret, i-ed[cnt]);
        }
        return ret;
    }
};