const int dirs[4][2]={0,1,0,-1,1,0,-1,0};
struct Node{
    unordered_map<char, Node*> d;
    bool is_answer;
    Node(){
        d.clear();
        is_answer=false;
    }
};

void dfs(int x, int y, string cs, Node* root, vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string>& ret){
    if (root->is_answer){
        ret.push_back(cs);
        root->is_answer=false;
    }
    if (root->d.size()==0) return;
    visited[x][y]=true;
    for (int k = 0;k < 4;k++){
        int nx = x+dirs[k][0], ny = y+dirs[k][1];
        if (nx>=0 &&  nx<board.size() && ny>=0 && ny<board[0].size() && !visited[nx][ny] && root->d.find(board[nx][ny])!=root->d.end()){
            
            dfs(nx, ny, cs+string(1,board[nx][ny]), root->d[board[nx][ny]], board, visited, ret);
        }
    }
    visited[x][y]=false;
}



class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        int n = board.size();
        if (n==0) return ret;
        int m = board[0].size();
        if (m==0) return ret;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        Node *root = new Node();
        for (auto w:words){
            Node *p=root;
            for (char c:w){
                if (p->d.find(c)==p->d.end()) p->d[c]=new Node();
                p = p->d[c];
            }
            p->is_answer=true;
        }
        for (int i = 0;i < n;i++)
            for (int j = 0; j < m;j++)
                if (root->d.find(board[i][j])!=root->d.end())
                    dfs(i, j, string(1,board[i][j]), root->d[board[i][j]], board, visited, ret);
        //sort(ret.begin(), ret.end());
        return ret;
    }
};