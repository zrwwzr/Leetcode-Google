class Solution {
public:
    /*  Let L[i][j] indicate whether s[0...i - 1] matches p[0...j - 1]
        1) L[i][j] = L[i - 1][j - 1] if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
        2) L[i][j] = L[i - 1][j] || L[i][j - 1] if(p[j - 1] == '*')
     */
    bool isMatch(string s, string p) {
        const size_t m = s.length(), n = p.length();
        vector<int> pre(n + 1, false), cur(n + 1, false);
        pre[0] = true;
        for(int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] && p[i - 1] == '*';
        for(int i = 1; i <= m; ++i){
            fill(cur.begin(), cur.end(), false);
            for(int j = 1; j <= n; ++j){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    cur[j] = pre[j - 1];
                else if(p[j - 1] == '*')
                    cur[j] = pre[j] || cur[j - 1];
            }
            pre.swap(cur);
        }
        return pre[n];
    }
};
