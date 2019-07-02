class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hcnt;
        for (int a:A)
            for (int b:B){
                if (hcnt.find(a+b)==hcnt.end()) hcnt[a+b]=0;
                hcnt[a+b]++;
            }
        int ret=0;
        for (int c:C)
            for (int d:D)
               if (hcnt.find(-(c+d))!=hcnt.end()) ret+=hcnt[-(c+d)]; 
        return ret;
    }
};