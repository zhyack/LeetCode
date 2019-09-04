// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    queue<char> buffer;
    Solution(){
        while(!buffer.empty()) buffer.pop();
    }
    int read(char *buf, int n) {
        char tmp[4];
        while(buffer.size()<n){
            int r = read4(tmp);
            if (r==0) break;
            for (int i = 0;i < r;i++) buffer.push(tmp[i]);
        }
        int ret = 0;
        for (int i = 0;i < n;i++){
            if (buffer.empty()) break;
            ret++;
            buf[i]=buffer.front();
            buffer.pop();
        }
        return ret;
    }
};