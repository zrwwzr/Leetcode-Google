class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n + 1, INT_MAX);
        vector<pair<int, int>> nodes;
        ugly[1] = 1;
        for(int i = 0; i < primes.size(); ++i)
            nodes.push_back(make_pair(1, primes[i]));
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < nodes.size(); ++j)
                ugly[i] = min(ugly[i], nodes[j].second);
            for(int j = 0; j < nodes.size(); ++j)
                if(nodes[j].second == ugly[i])
                    nodes[j].second = ugly[++nodes[j].first] * primes[j];
        }
        return ugly[n];
    }
};
