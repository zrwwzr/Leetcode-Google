class Solution {
public:
    void dfs(int start, long long sum, long long prev, const int &target, const string &s, string exp, vector<string> &res){
    	if(start == s.length() && sum == target)
    		res.push_back(exp);
    	long long num = 0;
    	for(int i = start; i < s.length(); ++i){
    		if(i > start && num == 0) break;
    		num = num * 10 + s[i] - '0';
    		string num_str = to_string(num);
    		if(!exp.empty()){
    			dfs(i + 1, sum + num, num, target, s, exp + "+" + num_str, res);
    			dfs(i + 1, sum - num, -num, target, s, exp + "-" + num_str, res);
    			dfs(i + 1, (sum - prev) + prev  * num, prev * num, target, s, exp + "*" + num_str, res);
    		}else{
    			dfs(i + 1, num, num, target, s, num_str, res);
    		}
    	}
    }
    
    vector<string> addOperators(string num, int target) {
    	vector<string> res;
    	string exp;
    	dfs(0, 0, 0, target, num, exp, res);
    	return res;
    }
};
