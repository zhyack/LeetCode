class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> m;
        unordered_map<int, int> mc;
        for (int i = 0;i < n-1; i++)
            for (int j = i+1; j < n;j++){
                int s = nums[i]+nums[j], k = min(nums[i], nums[j]);
                if (m.find(s)==m.end()) m[s]=unordered_set<int>();
                if (m[s].find(k)==m[s].end()) m[s].insert(k);
            }
        for (int i = 0;i < n;i++){
            if (mc.find(nums[i])==mc.end()) mc[nums[i]]=0;
            mc[nums[i]]++;
        }
        vector<vector<int>> ret;
        unordered_map<int, unordered_map<int, unordered_set<int>>> p;
        bool dealsame=false;
        for (unordered_map<int, unordered_set<int>>::iterator it=m.begin(); it!=m.end(); it++){
            int s = it->first;
            if (s>target-s || m.find(target-s)==m.end()) continue;
            if (s==target-s && dealsame) continue;
            unordered_set<int> um = it->second;
            unordered_set<int> om = m[target-s];
            for (unordered_set<int>::iterator jt=um.begin(); jt!=um.end(); jt++){
                for (unordered_set<int>::iterator kt=om.begin(); kt!=om.end(); kt++){
                    int a = *jt, b = s-*jt;
                    int c = *kt, d = target-s-*kt;
                    unordered_map<int, int> tmp(mc);
                    tmp[a]--; tmp[b]--; tmp[c]--; tmp[d]--;
                    if (tmp[a]<0 || tmp[b]<0 || tmp[c]<0 || tmp[d]<0) continue; 
                    vector<int> ans({a, s-a, c, target-s-c});
                    sort(ans.begin(), ans.end());
                    if (p.find(ans[0])==p.end())
                        p[ans[0]]=unordered_map<int, unordered_set<int>>();
                    if (p[ans[0]].find(ans[1])==p[ans[0]].end())
                        p[ans[0]][ans[1]]=unordered_set<int>();
                    if (p[ans[0]][ans[1]].find(ans[2])==p[ans[0]][ans[1]].end())
                        p[ans[0]][ans[1]].insert(ans[2]), ret.push_back(ans);
                }
            }
            if (s==target-s) dealsame=true;
        }
        return ret;
    }
};