class Solution {
public:
    int hIndex(vector<int>& citations) {
        const size_t n = citations.size();
        if(n == 0) return 0;
        vector<int> cnt(n + 1, 0);
        for(int i = 0; i < citations.size(); ++i){
            if(citations[i] > n) cnt[n]++;
            else cnt[citations[i]]++;
        }
        int total = 0;
        for(int i = n; i >= 0; --i){
            total += cnt[i];
            if(total >= i) return i;
        }
        return 0;
    }
};
