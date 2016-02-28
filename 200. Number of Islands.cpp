class Solution {
public:
    bool Union(int i, int j, vector<int> &parent){
        int pi = Find(i, parent), pj = Find(j, parent);
        if(pi == pj) return false;
        parent[pj] = pi;
        return true;
    }
    int Find(int i, const vector<int> &parent){
        return i == parent[i] ? i : Find(parent[i], parent);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        const size_t m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n, 0);
        for(int i = 0; i < m * n; ++i)
            parent[i] = i;
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    cnt++;
                    if(i < m - 1 && grid[i + 1][j] == '1' && Union(i * n + j, (i + 1) * n + j, parent))
                        cnt--;
                    if(j <n - 1 && grid[i][j + 1] == '1' && Union(i * n + j, i * n + j + 1, parent))
                        cnt--;
                }
            }
        }
        return cnt;
    }
};
