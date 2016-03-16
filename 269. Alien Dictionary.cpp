class Solution {
public:
    string alienOrder(vector<string>& words) {
    	if(words.empty()) return "";
    	indegree.resize(26, 0);
    	buildGraph(words);
    	return topologicalSort();
    }
private:
    unordered_map<int, vector<int>> g;
    vector<int> indegree;
    void buildGraph(const vector<string> &words){
        for(int i = 0; i < words.size(); ++i)
    		for(int j = 0; j < words[i].size(); ++j)
    			if(g.find(words[i][j]) == g.end())
    			    g[words[i][j] - 'a'] = vector<int>();
    	for(int i = 1; i < words.size(); ++i)
    		addEdge(words[i - 1], words[i]);
    }
    void addEdge(const string &word1, const string &word2){
    	for(int i = 0, j = 0; i < word1.length() && j < word2.length(); ++i, ++j){
    		if(word1[i] != word2[j]){
    		    g[word1[i] - 'a'].push_back(word2[j] - 'a');
    		    indegree[word2[j] - 'a']++;
    			return;
    		}
    	}
    }
    string topologicalSort(){
        string res = "";
        queue<int> q;
    	for(unordered_map<int, vector<int>>::iterator it = g.begin(); it != g.end(); ++it)
    		if(indegree[it->first] == 0)
    			q.push(it->first);
    	int cur;
    	while(!q.empty()){
    		cur= q.front(), q.pop();
    		res.append(1, 'a' + cur);
    		for(int i = 0; i < g[cur].size(); ++i)
    			if(--indegree[g[cur][i]] == 0)
    				q.push(g[cur][i]);
    	}
    	for(int i = 0; i < indegree.size(); ++i)
    		if(indegree[i] != 0) return "";
    	return res;
    }
};
