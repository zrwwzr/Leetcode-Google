class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        int depth = 1;
        for(int i = 1; i * i <= n; ++i){
            squares.push_back(i * i);
            visited[i * i] = true;
            q.push(i * i);
        }
        if(n == squares.back()) return depth;
        while(!q.empty()){
            int size = q.size(); 
            depth++;
            for(int i = 0; i < size; ++i){
                int cur = q.front();
                q.pop();
                for(int j = 0; j < squares.size(); ++j){
                    int next = squares[j] + cur;
                    if(next > n) break;
                    else if(next == n) return depth;
                    else if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
        
        return 0;
    }
};
