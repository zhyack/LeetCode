class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> q;
        q.clear();
        vector<int> order;
        order.clear();
        for (int i = 0;i<n;i++) q.push_back(i);
        for (int i = 0;i<n;i++){
            order.push_back(q.front());
            q.pop_front();
            q.push_back(q.front());
            q.pop_front();
        }
        vector<int> ans(n,0);
        for (int i = 0;i<n;i++) ans[order[i]]=deck[i];
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> deck = stringToIntegerVector(line);
        
        vector<int> ret = Solution().deckRevealedIncreasing(deck);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}