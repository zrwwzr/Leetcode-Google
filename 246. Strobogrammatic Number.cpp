class Solution {
public:
    unordered_map<char, char> map = {{'0','0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    bool isStrobogrammatic(string num) {
        const size_t n = num.length();
        if(n == 0) return true;
        int left = 0, right = n - 1, mid = (left + right) / 2;
        if(n % 2 != 0 && num[mid] != '0' && num[mid] != '1' && num[mid] != '8')
            return false;
        while(left < right){
            if(map[num[left++]] != num[right--])
                return false;
        }
        return true;
    }
};
