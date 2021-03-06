class Solution {
public:
    int calculate(string s) {
        stack<int> results;
        stack<char> ops;
        bool is_new_num=true;
        int current_num;
        for (char c:s){
            if (not(c>='0' && c<='9' || c=='+' || c=='-' || c=='*' || c=='/')) continue;
            if (c>='0' && c<='9'){
                if (is_new_num){
                    current_num=0;
                    is_new_num=false;
                }
                current_num=current_num*10+(c-'0');
            }
            else{
                results.push(current_num);
                // cout << "push:" << current_num << endl; 
                is_new_num=true;
                while (!ops.empty() && (c=='+'|| c=='-' || ops.top()=='*' || ops.top()=='/')){
                    int v1 = results.top();
                    results.pop();
                    int v2 = results.top();
                    results.pop();
                    if (ops.top()=='+') results.push(v2+v1);
                    else if (ops.top()=='-') results.push(v2-v1);
                    else if (ops.top()=='*') results.push(v2*v1);
                    else if (ops.top()=='/') results.push(v2/v1);
                    // cout << "calc:" << v2 << ops.top() << v1 << "=" << results.top() <<  endl;
                    ops.pop();
                }
                ops.push(c);
                // cout << "push:" << c << endl;
            }
        }
        results.push(current_num);
        // cout << "push:" << current_num << endl; 
        while (!ops.empty()){
            int v1 = results.top();
            results.pop();
            int v2 = results.top();
            results.pop();
            if (ops.top()=='+') results.push(v2+v1);
            else if (ops.top()=='-') results.push(v2-v1);
            else if (ops.top()=='*') results.push(v2*v1);
            else if (ops.top()=='/') results.push(v2/v1);
            // cout << "calc:" << v2 << ops.top() << v1 << "=" << results.top() <<  endl;
            ops.pop();
        }
        return results.top();
    }
};