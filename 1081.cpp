class Solution {
public:
    string smallestSubsequence(string text) {
        stack<char> ans;
        unordered_map<char, int> m;
        unordered_set<char> in_stack;
        for (auto c:text) m[c]++;
        for (auto c:text){
            while(!ans.empty() && in_stack.find(c)==in_stack.end() && m[ans.top()]>0 && c<=ans.top()){
                in_stack.erase(ans.top());
                ans.pop();
            }
            if (in_stack.find(c)==in_stack.end()) ans.push(c), in_stack.insert(c);
            m[c]--;
        }
        string ret = "";
        while(!ans.empty()){
            ret+=ans.top();
            ans.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};