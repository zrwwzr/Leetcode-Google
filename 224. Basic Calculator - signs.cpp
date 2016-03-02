class Solution {
public:
    int calculate(string s) {
        int total = 0, num;
        vector<int> signs(2, 1);
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' ') continue;
            else if(s[i] == '(') signs.push_back(signs.back());
            else if(s[i] == ')') signs.pop_back();
            else if(s[i] == '+' || s[i] == '-') signs.push_back(signs.back() * (s[i] == '+' ? 1 : -1));
            else{
                num = 0;
                while(i < s.length() && isdigit(s[i]))
                    num = num * 10 + s[i++] - '0';
                total += num * signs.back();
                signs.pop_back();
                i--;
            }
        }
        return  total;
    }
};
