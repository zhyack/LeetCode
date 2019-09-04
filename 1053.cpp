class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        stack<pair<int,int>> s;
        int retl=-1, retr=-1;
        int n = A.size();
        for (int i = 0;i < n;i++){
            while(!s.empty() && A[i]>=s.top().first) s.pop();
            if (!s.empty()){
                if (s.top().second>retl || s.top().second==retl && A[i]>A[retr]){
                   retl = s.top().second;
                retr = i; 
                }
            }
            s.push(make_pair(A[i],i));
        }
        if (retl==-1) return A;
        else{
            swap(A[retl], A[retr]);
            return A;
        }
        
    }
};