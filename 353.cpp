class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    queue<pair<int,int>> food, snake;
    unordered_set<int> forbid;
    int width, height;
    int c_x, c_y, d; 
    const int dirs[4][2]={-1,0,0,-1,1,0,0,1};
    
    int encode(int x, int y){
        return (x+1)*(this->width+2)+y+1;
    }
    
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        while(!this->food.empty()) this->food.pop();
        for (auto f:food) this->food.push(make_pair(f[0], f[1]));
        this->width=width;
        this->height=height;
        this->c_x=0;
        this->c_y=0;
        while(!this->snake.empty()) this->snake.pop();
        this->snake.push(make_pair(this->c_x, this->c_y));
        this->forbid.clear();
        this->forbid.insert(encode(this->c_x, this->c_y));
        for (int i = -1;i <= this->width; i++) this->forbid.insert(this->encode(-1, i));
        for (int i = -1;i <= this->width; i++) this->forbid.insert(this->encode(this->height, i));
        for (int i = -1;i <= this->height; i++) this->forbid.insert(this->encode(i, -1));
        for (int i = -1;i <= this->height; i++) this->forbid.insert(this->encode(i, this->width));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int nd=-1;
        if (direction=="U") nd=0;
        else if (direction=="L") nd=1;
        else if (direction=="D") nd=2;
        else if (direction=="R") nd=3;
        int nx = this->c_x+this->dirs[nd][0], ny=this->c_y+this->dirs[nd][1];
        if (nx!=this->food.front().first || ny!=this->food.front().second){
            this->forbid.erase(this->encode(this->snake.front().first, this->snake.front().second));
            this->snake.pop();
        }
        else{
            this->food.pop();
        }
        if (this->forbid.find(this->encode(nx, ny))!=this->forbid.end()) return -1;
        this->forbid.insert(this->encode(nx, ny));
        this->c_x=nx;
        this->c_y=ny;
        this->snake.push(make_pair(this->c_x, this->c_y));
        return this->snake.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */