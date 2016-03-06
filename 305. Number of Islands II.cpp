class Union_Find{
public:
    Union_Find(int n){
        parents.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; ++i)
            parents[i] = i;
    }
    bool Find(int x, int y){
        return Parent(x) == Parent(y);
    }
    void Union(int x, int y){
        int px = Parent(x), py = Parent(y);
        if(size[px] > size[py]){
            parents[py] = px;
            size[px] += size[py];
        }else{
            parents[px] = py;
            size[py] += size[px];
        }
    }
private:
    vector<int> parents, size;
    int Parent(int x){
        while(x != parents[x]){
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }
};
class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        vector<bool> isLand(m * n, false);
        Union_Find uf(m * n);
        int cnt = 0, cur, next, x, y, col, row;
        for(int i = 0; i < positions.size(); ++i){
            cnt++;
            row = positions[i].first, col = positions[i].second;
            cur = row * n + col;
            isLand[cur] = true;
            for(int j = 0; j < 4; ++j){
                x = col + dx[j], y = row + dy[j];
                next = y * n + x;
                if(x >= 0 && x < n && y >= 0 && y < m && isLand[next]){
                    if(!uf.Find(cur, next)){ 
                        uf.Union(cur, next);
                        cnt--;
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};
