class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i = 0; i < strs.size(); ++i)
            encoded.append(to_string(strs[i].length())).append("#").append(strs[i]);
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int start = 0, end = 0, len = 0;
        while(start < s.length()){
            end = s.find_first_of('#', start);
            if(end == string::npos) break;
            len = stoi(s.substr(start, end - start));
            res.push_back(s.substr(end + 1, len));
            start = end + len + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
