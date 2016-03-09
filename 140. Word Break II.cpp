class Solution {
public:
    void dfs(int start, string &sentence, vector<string> &res, const string &s, const unordered_set<string> &dict, const vector<bool> &breakable){
        if(start == s.length()) res.push_back(sentence.substr(0, sentence.size() - 1));
        string substr, origin = sentence;
        for(int i = start; i < s.length(); ++i){
            substr = s.substr(start, i - start + 1);
            if(dict.find(substr) != dict.end() && breakable[i + 1]){
                sentence.append(substr).append(" ");
                dfs(i + 1, sentence, res, s, dict, breakable);
                sentence = origin;
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        const size_t n = s.length();
        vector<string> res;
        string sentence = "", substr;
        vector<bool> breakable(n + 1, false);
        breakable[n] = true;
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                substr = s.substr(i, j - i + 1);
                if(breakable[j + 1] && wordDict.find(substr) != wordDict.end())
                    breakable[i] = true;
            }
        }
        dfs(0, sentence, res, s, wordDict, breakable);
        return res;
    }
};
