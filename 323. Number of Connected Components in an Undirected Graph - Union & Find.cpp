class Solution {
public:
    bool Union(int i, int j, vector<int> &parents){
        if(i > j) return Union(j, i, parents);
        int pi = Find(i, parents), pj = Find(j, parents);
        if(pi == pj) return false;
        parents[pj] = pi;
        return true;
    }
    
    int Find(int i, const vector<int> &parents){
        return i == parents[i] ? i : Find(parents[i], parents);
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parents(n, 0);
        for(int i = 0; i < n; ++i)
            parents[i] = i;
        int cnt = n;
        for(int i = 0; i < edges.size(); ++i){
            if(Union(edges[i].first, edges[i].second, parents))
                cnt--;
        }
        return cnt;
    }
};
