/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
const int dirs[4][2]={1,0,0,1,-1,0,0,-1};
void dfs(int x, int y, int d, Robot& robot, set<pair<int, int>> &s){
    s.insert(make_pair(x, y));
    robot.clean();
    for (int k = 0;k < 4; k++){
        d = (d+1)%4;
        int nx = x+dirs[d][0], ny=y+dirs[d][1];
        robot.turnLeft();
        if (s.find(make_pair(nx, ny))==s.end() && robot.move()){
            dfs(nx, ny, d, robot, s);
            robot.turnLeft();
            robot.turnLeft();
            robot.move();
            robot.turnLeft();
            robot.turnLeft();
        }
    }
}

class Solution {
public:
    void cleanRoom(Robot& robot) {
        set<pair<int, int>> s;
        dfs(0,0,0,robot,s);
    }
};