class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int p = 0, m = flowerbed.size();
        while(p<m){
            if (! (flowerbed[p]==1 || p>0 && flowerbed[p-1]==1 || p<m-1 && flowerbed[p+1]==1) ) 
                flowerbed[p]=1, n--;
            p++;
        }
        return n<=0;
    }
};