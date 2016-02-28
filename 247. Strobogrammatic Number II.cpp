class Solution {
public:
    vector<pair<string, string>> pairs = {{"0","0"}, {"1","1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}};
    vector<string> findStrobogrammatic(int n, int m){
        if(n == 0) return {""};
        if(n == 1) return {"0", "1", "8"};
        vector<string> res, temp;
        temp = findStrobogrammatic(n - 2, m);
        for(int i = 0; i < temp.size(); ++i){
            for(int j = 0; j < pairs.size(); ++j){
                if(m == n && j == 0)
                    continue;
                res.push_back(pairs[j].first + temp[i] + pairs[j].second);
            }
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammatic(n, n);
    }
};
