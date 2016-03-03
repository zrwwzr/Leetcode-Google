class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return true;
        if(n != edges.size() + 1) return false;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        queue<int> q;
        q.push(0);
        int cur;
        vector<int> neighbors;
        while(!q.empty()){
            cur = q.front(), q.pop();
            visited[cur] = true;
            neighbors = graph[cur];
            for(int i = 0; i < neighbors.size(); ++i)
                if(!visited[neighbors[i]])
                    q.push(neighbors[i]);
        }
        for(int i = 0; i < n; ++i)
            if(!visited[i]) return false;
        return true;
            
        
    }
};
