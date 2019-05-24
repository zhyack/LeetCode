class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> forward(n,-1), backward(n,n);
        stack<int> small;
        while(!small.empty()) small.pop();
        for (int i = 0;i < n;i++){
            while(!small.empty() && heights[small.top()]>=heights[i]) small.pop();
            if (!small.empty()) forward[i]=small.top();
            small.push(i);
        }
        while(!small.empty()) small.pop();
        for (int i = n-1;i >= 0;i--){
            while(!small.empty() && heights[small.top()]>=heights[i]) small.pop();
            if (!small.empty()) backward[i]=small.top();
            small.push(i);
        }
        int ans = 0;
        for (int i = 0;i < n;i++) ans=max(ans, heights[i]*(backward[i]-forward[i]-1));
        return ans;
    }
};