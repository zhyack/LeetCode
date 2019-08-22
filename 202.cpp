class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if (s.find(n)!=s.end()) return false;
            s.insert(n);
            int k = n, sum=0;
            while(k){
                sum+=(k%10)*(k%10);
                k/=10;
            }
            n = sum;
        }
        return true;
    }
};