class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int first = -1, second = -1, start = 0, max_len = 0;
        for(int i = 0; i < s.length(); ++i){
            if(first == -1 || s[i] == s[first])
                first = i;
            else if(second == -1 || s[i] == s[second])
                second = i;
            else{
                max_len = max(max_len, i - start);
                if(s[i - 1] == s[second]){
                    start = first + 1;
                    first = second;
                }else
                    start = second + 1;
                second = i;
            }
        }
        max_len = max(max_len, (int)s.length() - start);
        return max_len;
    }
};
