class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend, b = divisor;
        long long c = a/b;
        if (c!=(int) c){
            c = 1;
            c = (c<<31)-1;
        }
        return c;
    }
};