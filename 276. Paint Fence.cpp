class Solution {
public:
    int numWays(int n, int k) {
        if(n == 1) return k;
        if(n == 2) return k * k;
        if(n == 0 || k < 2) return 0;
        vector<int> cnt(n + 1, 0);
        cnt[1] = k, cnt[2] = k * k;
        for(int i = 3; i <= n; ++i){
            cnt[i] = (cnt[i - 2] + cnt[i - 1]) * (k - 1) ;
        }
        return cnt[n];
    }
};
