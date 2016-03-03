class Solution {
public:
    void dfs(int cur, vector<vector<int>> &graph, vector<bool> &visited){
        if(visited[cur]) return;
        visited[cur] = true;
        vector<int> neighbor = graph[cur];
        for(int i = 0; i < neighbor.size(); ++i)
            dfs(neighbor[i], graph, visited);
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return true;
        if(n != edges.size() + 1) return false;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        dfs(0, graph, visited);
        for(int i = 0; i < n; ++i)
            if(!visited[i]) return false;
        return true;
    }
};
