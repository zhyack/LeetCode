class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ret = -1e5;
        int n = arr.size();
        vector<int> forward(n), backward(n);
        int sum = 0;
        for (int i = 0;i < n;i++){
            forward[i]=sum;
            sum += arr[i];
            if (sum < 0) sum=0;
        }
        sum = 0;
        for (int i = n-1;i >=0;i--){
            backward[i] = sum;
            sum += arr[i];
            if (sum<0) sum=0;
        }
        for (int i = 0;i < n;i++){
            if (forward[i]==backward[i] && forward[i]==0){
                ret = max(ret, arr[i]);
            }
            else ret = max(ret, forward[i]+backward[i]);
        }
        return ret;
    }
};