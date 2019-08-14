class Solution {
public:
    int compress(vector<char>& chars) {
        int ret = 0;
        int cnt = 0;
        char last='\0';
        chars.push_back('\1');
        for (char c:chars){
            if (c==last) cnt++;
            else{
                if (last>1){
                    chars[ret++]=last;
                    if (cnt>1){
                        int m = 0;
                        while(cnt){
                            chars[ret+(m++)]='0'+cnt%10;
                            cnt/=10;
                        }
                        for (int i = 0;i < m/2;i++) swap(chars[ret+i], chars[ret+m-i-1]);
                        ret += m;
                    }
                }
                last = c;
                cnt = 1;
            }
        }
        return ret;
    }
};