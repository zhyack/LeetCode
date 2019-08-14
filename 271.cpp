class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ret="";
        for (auto s:strs){
            ret.append(1, '\1');
            for (auto c:s){
                if (c>=0 && c<128){
                    ret.append(1, '\0');
                    ret.append(1, char(c+128));
                }
                else ret.append(1, c);
            }
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ret;
        int n = -1;
        bool b = false;
        for (auto c:s){
            if (c<0){
                if (b) ret[n].append(1, char(c+128));
                else ret[n].append(1, c);
                b = false;
            }
            if (c=='\1'){
                ret.push_back("");
                n++;
            }
            if (c=='\0') b=true;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));