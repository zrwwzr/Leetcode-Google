class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1 || edges.empty()) return vector<int>(1, 0);
        vector<int> indegree(n, 0), neighbors, res;
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); ++i){
            indegree[edges[i].first]++;
            indegree[edges[i].second]++;
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(indegree[i] == 1)
                q.push(i);
        while(n > 2){
            size_t size = q.size();
            for(int i = 0; i < size; ++i){
                int cur = q.front();
                q.pop();
                n--;
                neighbors = graph[cur];
                for(int j = 0; j < neighbors.size(); ++j)
                    if(--indegree[neighbors[j]] == 1)
                        q.push(neighbors[j]);
            }
        }
        while(!q.empty()) res.push_back(q.front()), q.pop();
        return res;
    }
};
