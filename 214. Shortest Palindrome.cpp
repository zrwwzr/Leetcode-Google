class Solution {
public:
    int palindrome(const string &s, int left, int right){
        while(left >= 0)
            if(s[left--] != s[right++]) return -1;
        return --right;
    }
    string shortestPalindrome(string s) {
        const size_t n = s.length();
        if(n == 0) return s;
        int right, i;
        for(i = n / 2; i > 0; --i){
            right = palindrome(s, i, i);
            if(right != -1) break;
            right = palindrome(s, i - 1, i);
            if(right != -1) break;
        }
        if(right == n - 1) return s;
        string temp = i !=0 ? s.substr(right + 1) : s.substr(i + 1);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
};
