class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i = 0; i < dictionary.size(); ++i){
            if(word_set.find(dictionary[i]) == word_set.end()){
                abbr_cnt[getAbbr(dictionary[i])]++;
                word_set.insert(dictionary[i]);
            }
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        if(word_set.find(word) != word_set.end())
            return abbr_cnt[abbr] == 1;
        else 
            return abbr_cnt[abbr] == 0;
    }
private:
    unordered_map<string, int> abbr_cnt;
    unordered_set<string> word_set;
    inline string getAbbr(const string &word){
        if(word.length() <= 2) return word; 
        return word.substr(0, 1).append(to_string(word.length() - 1)).append(1, word[word.length() - 1]);
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
