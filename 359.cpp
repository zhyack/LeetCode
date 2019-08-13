class Logger {
public:
    /** Initialize your data structure here. */
    queue<pair<int, string>> q;
    unordered_map<string, unordered_set<int>> m; 
    Logger() {
        while(!q.empty()) q.pop();
        m.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(!q.empty() && timestamp-q.front().first>=10){
            if (m.find(q.front().second)!=m.end() && m[q.front().second].find(q.front().first)!=m[q.front().second].end())
                m[q.front().second].erase(q.front().first);
            if (m.find(q.front().second)!=m.end() && m[q.front().second].size()==0) m.erase(q.front().second);
            q.pop();
        }
        if (m.find(message)!=m.end()) return false;
        m[message].insert(timestamp);
        q.push(make_pair(timestamp, message));
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */