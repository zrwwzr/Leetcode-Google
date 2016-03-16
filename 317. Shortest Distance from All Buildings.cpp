class Solution {
public:
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    int bfs(int i, int j, const vector<vector<int>> &grid){
        const size_t m = grid.size(), n = grid[0].size();
        int depth = 0, cnt = 1, sum = 0, x, y, dx, dy, cur, size;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<int> q;
        q.push(i * n + j), visited[i][j] = true;
        while(!q.empty()){
            depth++;
            size = q.size();
            for(int k = 0; k < size; ++k){
                cur = q.front(), q.pop();
                x = cur % n, y = cur / n;
                for(int p = 0; p < 4; ++p){
                    dx = dirx[p] + x, dy = diry[p] + y;
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m){
                        if(visited[dy][dx]) continue;
                        cnt++;
                        visited[dy][dx] = true;
                        if(grid[dy][dx] == 1) sum += depth;
                        else if(grid[dy][dx] == 0) q.push(dy * n + dx);
                    }
                }
            }
        }
        return cnt == m * n ? sum : -1;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        static int i = 0;
        cout<<i++<<endl;
        const size_t m = grid.size(), n = grid[0].size();
        int minDist = INT_MAX;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0)
                    minDist = min(bfs(i, j, grid), minDist);
            }
        }
        return minDist;
    }
};
