class Solution {
public:
    bool isPalindrome(const string &s){
        int left = 0, right = s.length() - 1;
        while(left < right)
            if(s[left++] != s[right--]) return false;
        return true;
    }
    void addPairs(int i, int j, vector<vector<int>> &res){
        vector<int> idx;
        idx.push_back(i), idx.push_back(j);
        res.push_back(idx);
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        vector<int> idx;
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); ++i)
            map[words[i]] = i;
        for(int i = 0; i < words.size(); ++i){
            if(words[i] == "") continue;
            string str = words[i];
            if(isPalindrome(str) && map.find("") != map.end()){
                addPairs(map[""], i, res);
                addPairs(i, map[""], res);
            }
            reverse(str.begin(), str.end());
            if(map.find(str) != map.end() && map[str] != i)
                addPairs(map[str], i, res);
            for(int j = 0; j < words[i].length() - 1; ++j){
                string left = words[i].substr(0, j + 1), right = words[i].substr(j + 1);
                string left_r = left, right_r = right;
                reverse(left_r.begin(), left_r.end()), reverse(right_r.begin(), right_r.end());
                if(isPalindrome(left) && map.find(right_r) != map.end() && map[right_r] != i)
                    addPairs(map[right_r], i, res);
                if(isPalindrome(right) && map.find(left_r) != map.end() && map[left_r] != i)
                    addPairs(i, map[left_r], res);
            }
        }
        return res;
    }
};
