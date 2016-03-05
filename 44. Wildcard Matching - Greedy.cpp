class Solution {
public:
    /*
    explanation:
    Two pointers i and j scane s and p:
    1) if(s[i] == p[j] || p[j] == '?') this is one character matching case, advance both pointers one step
    2) if(p[j] == '*') we will try our best to match the character of p[j + 1] with s[i] onward until we find a match or return false
       we will need to keep record of the index of i and j when p[j] == '*'.
       Example:
               s_pos
                 |
                 V 
       s[] = d b c e f g      in the case on the left side, after we find the *, we keep record of s_pos and p_pos, then we 
                  \|/         try to match: 
       p[] = d b * ? g *      1) '?' with 'c', it is match, then i and j advance one step, but 'e' and 'g' is not a match
                 ^ j          since we have recorded the last * index, we could fallback and try the next possible position
                 |            2) '?' with 'e', but still no luck for 'g' and 'f', fallback to the next possible possition
               p_pos          3) '?' with f, the we have the final match 'g' and 'g'
                              Finally if p didn't reach the end we also need to check whether all remaining characters are '*'
    */
    bool isMatch(string s, string p) {
        const size_t m = s.length(), n = p.length();
        int i = 0, j = 0, s_pos = -1, p_pos = -1;
        while(i < m){
            if(j < n && (s[i] == p[j] || p[j] == '?')) i++, j++;
            else if(j < n && p[j] == '*') s_pos = i, p_pos = j++;
            else if(p_pos != -1) i = ++s_pos, j = p_pos + 1;
            else return false;
        }
        while(j < n && p[j] == '*') j++;
        return j == n;
    }
};
