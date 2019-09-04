class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        if (n==0) return 0;
        vector<int> s(arr.begin(), arr.end());
        sort(s.begin(), s.end());
        int max_val = s[0], min_val = s[n-1], ret = 0;
        vector<bool> fw(n, false), bw(n, false);
        for (int i = 0;i < n;i++){
            max_val = max(max_val, arr[i]);
            if (max_val<=s[i]) fw[i]=true;
        }
        for (int i = n-1;i>=0;i--){
            min_val = min(min_val, arr[i]);
            if (min_val>=s[i]) bw[i] = true;
        }
        for (int i = n-2;i>=0;i--) if (fw[i] && bw[i+1]) ret++;
        return ret+1;
    }
};