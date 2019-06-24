class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1, ret=0;
        while(l<r){
            ret = max(ret, (r-l)*min(height[r], height[l]));
            if (height[r]<height[l]) r--;
            else l++;
        }
        return ret;
    }
};