class Solution {
public:
    const char deliminator = ',';
    const string null = "#";
    bool isValidSerialization(string preorder) {
    	vector<string> stack;
    	vector<string> tokens;
    	string token;
    	istringstream iss(preorder);
    	while(getline(iss, token, deliminator))
    	    tokens.push_back(token);
    	for(int i = 0; i < tokens.size(); ++i){
    		stack.push_back(tokens[i]);
    		while(stack.size() > 2 && stack.back() == null && stack[stack.size() - 2] == null && stack[stack.size() - 3] != null){
    			stack.pop_back(), stack.pop_back(), stack.pop_back();
    			stack.push_back(null);
    		}
    	}
    	return stack.size() == 1 && stack.back() == null;
    }
};
