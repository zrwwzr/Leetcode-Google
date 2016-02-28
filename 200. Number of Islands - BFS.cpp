class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        const size_t m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<int> q;
        int cnt = 0, r, c;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(visited[i][j]) continue;
                visited[i][j] = true;
                if(grid[i][j] == '1'){
                    cnt++;
                    q.push(i * n + j);
                    while(!q.empty()){
                        r = q.front() / n;
                        c = q.front() % n;
                        q.pop();
                        if(r > 0 && grid[r - 1][c] == '1' && !visited[r - 1][c]){
                            q.push((r - 1) * n + c);
                            visited[r - 1][c] = true;
                        }
                        if(c > 0 && grid[r][c - 1] == '1' && !visited[r][c - 1]){
                            q.push(r * n + c - 1);
                            visited[r][c - 1] = true;
                        }
                        if(r < m - 1 && grid[r + 1][c] == '1' && !visited[r + 1][c]){
                            q.push((r + 1) * n + c);
                            visited[r + 1][c] = true;
                        }
                        if(c < n - 1 && grid[r][c + 1] == '1' && !visited[r][c + 1]){
                            q.push(r * n + c + 1);
                            visited[r][c + 1] = true;
                        }
                            
                    }
                }
                    
            }
        }
        return cnt;
    }
};
