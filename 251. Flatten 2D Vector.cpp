class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(int i = 0; i < vec2d.size(); ++i){
            if(vec2d[i].empty()) continue;
            pairs.push_back(make_pair(vec2d[i].begin(), vec2d[i].end()));
        }
        cnt = 0;
    }

    int next() {
        int rtn = *(pairs[cnt].first++);
        if(pairs[cnt].first == pairs[cnt].second)
            pairs.erase(pairs.begin() + cnt);
        return rtn;
    }

    bool hasNext() {
        return pairs.size() > 0;
    }
private: 
    vector<pair<vector<int>::iterator, vector<int>::iterator>> pairs;
    int cnt;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
