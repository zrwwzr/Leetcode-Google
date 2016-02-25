class Solution {
public:
    unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};
    inline bool left(const char &c){
        return c == '(' || c == '{' || c == '[';
    }
    bool isValid(string s) {
        const size_t n = s.length();
        if(n == 0 || n % 2 != 0) return false;
        vector<char> stack;
        for(int i = 0; i < n; ++i){
            if(left(s[i]))
                stack.push_back(s[i]);
            else{
                if(stack.empty() || map[s[i]] != stack.back())
                    return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
