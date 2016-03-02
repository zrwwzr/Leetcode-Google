class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, first, second;
        char op;
        vector<int> operands;
        vector<char> operators;
        for(int i = 0; i <= s.length(); ++i){
            if(i == s.length() || s[i] == ')' || s[i] == '+' || s[i] == '-'){
                while(!operators.empty() && (i == s.length() || operators.back() != '(')){
                    op = operators.back(), operators.pop_back();
                    second = operands.back(), operands.pop_back();
                    first  = operands.back(), operands.pop_back();
                    operands.push_back(op == '+' ? first + second : first - second);
                }
                if(i == s.length()) break;
                else if(s[i] == ')')
                    operators.pop_back();
                else 
                    operators.push_back(s[i]);
            }
            else if(s[i] == ' ') continue;
            else if(s[i] == '(')
                operators.push_back(s[i]);
            else{
                num = 0;
                while(isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';
                operands.push_back(num);
                i--;
            }
        }
        
        return operands.back();
    }
};
