class Solution {
public:
    int numSquares(int n) {
        vector<int> cnt(n + 1, n);
        cnt[0] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j * j <= i; ++j)
                cnt[i] = min(cnt[i], cnt[i - j * j] + 1);
        return cnt[n];
    }
};
