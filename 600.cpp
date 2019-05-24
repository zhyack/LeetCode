class Solution {
public:
    int findIntegers(int num) {
        vector<int> bb({0, 1}), nn({0, 1});
        int ans=0, p=1;
        while(num>0){
            nn.push_back(num&1);
            num>>=1;
            bb.push_back(bb[p-1]+bb[p]);
            p++;
        }
        bool cont = false;
        for (int i = p;i > 0; i--){
            if (nn[i]){
                ans+=bb[i];
                if (cont) break;
                cont=true;
            }
            else cont=false;
        }
        return ans;
    }
};