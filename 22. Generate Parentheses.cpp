class Solution {
public:
    void dfs(int left, int right, string &comb, vector<string> &res){
        if(left == 0 && right == 0){
            res.push_back(comb);
            return;
        }
        if(left > 0){
            comb.push_back('(');
            dfs(left - 1, right, comb, res);
            comb.pop_back();
        }
        if(right > left){
            comb.push_back(')');
            dfs(left, right - 1, comb, res);
            comb.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string comb = "";
        dfs(n, n, comb, res);
        return res;
    }
};
