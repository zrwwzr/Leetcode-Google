class Solution {
public:
    int dir_col[4] = {0, 0, -1, 1};
    int dir_row[4] = {-1, 1, 0, 0};
    int dfs(int i, int j, const vector<vector<int>> &matrix, vector<vector<int>> &cnt){
        if(cnt[i][j] > 0) return cnt[i][j];
        int c, r;
        for(int k = 0; k < 4; ++k){
            r = dir_row[k] + i, c = dir_col[k] + j;
            if(r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size() && matrix[r][c] > matrix[i][j])
                cnt[i][j] = max(cnt[i][j], dfs(r, c, matrix, cnt));
        }
        return ++cnt[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        const size_t m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        int max_len = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                max_len = max(max_len, dfs(i, j, matrix, cnt));
        return max_len;
    }
};
