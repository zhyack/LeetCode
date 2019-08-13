class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ret = 0;
        for (int i = 1;i < sqrt(N)*2; i++)
            if (i%2==1 && N%i==0 && N/i-i/2>=1 || i%2==0 && N%(i/2)==0 && N/(i/2)%2==1 && (N/(i/2)-1)/2-(i/2)+1>=1) ret++;
        return ret;
    }
};