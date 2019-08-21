class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        while (V--){
            heights[K]++;
            int p = K, last=K;
            while(p>0 && heights[p]>=heights[p-1]+1){
                if (heights[p-1]<heights[p]-1) last=p-1;
                heights[p]--;
                heights[p-1]++;
                p--;
            }
            heights[p]--;
            heights[last]++;
            if (last!=K) continue;
            p = K;
            last=K;
            while(p<n-1 && heights[p]>=heights[p+1]+1){
                if (heights[p+1]<heights[p]-1) last=p+1;
                heights[p]--;
                heights[p+1]++;
                p++;
            }
            heights[p]--;
            heights[last]++;
            if (last!=K) continue;
            
        }
        return heights;
    }
};