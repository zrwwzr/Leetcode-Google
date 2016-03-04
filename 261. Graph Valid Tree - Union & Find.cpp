class Solution {
public:
    bool Union(int x, int y, vector<int> &parents){
        if(x > y) return Union(y, x, parents);
        int px = Find(x, parents), py = Find(y, parents);
        if(px == py) return false;
        parents[py] = px;
        return true;
    }
    int Find(int x, const vector<int> &parents){
        return x == parents[x] ? x : Find(parents[x], parents);
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return true;
        if(n != edges.size() + 1) return false;
        int cnt = n - 1;
        vector<int> parents(n, 0);
        for(int i = 0; i < n; ++i)
            parents[i] = i;
        for(int i = 0; i < edges.size(); ++i){
            if(Union(edges[i].first, edges[i].second, parents))
                cnt--;
        }
        return cnt == 0;
    }
};
