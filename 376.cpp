int calc(int x, int y){
    if (x>y) return 1;
    else if (x==y) return 0;
    else return -1;
}
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return n;
        int b = 0, ret=1;
        for (int i = 1;i < n; i++){
            int c = calc(nums[i-1], nums[i]);
            if (b && c && b!=c) ret++;
            if (c) b = c;
        }
        if (ret>1 || nums[n-1]!=nums[0]) ret++;
        return ret;
    }
};