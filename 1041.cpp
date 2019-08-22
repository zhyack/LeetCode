class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        int dirs[4][2]={0,1,-1,0,0,-1,1,0};
        for (char c:instructions){
            if (c=='G') x+=dirs[d][0], y+=dirs[d][1];
            else if (c=='L') d = (d+1)%4;
            else if (c=='R') d = (d+3)%4;
        }
        if (d==0 && (x||y)) return false;
        else return true;
    }
};