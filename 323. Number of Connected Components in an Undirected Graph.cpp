class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        queue<int> q;
        vector<int> visited(n, false), neighbors;
        int cnt = 0, cur;
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                cnt++;
                visited[i] = true;
                q.push(i);
                while(!q.empty()){
                    cur = q.front(), q.pop();
                    neighbors = graph[cur];
                    for(int j = 0; j < neighbors.size(); ++j){
                        if(!visited[neighbors[j]]){
                            visited[neighbors[j]] = true;
                            q.push(neighbors[j]);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
