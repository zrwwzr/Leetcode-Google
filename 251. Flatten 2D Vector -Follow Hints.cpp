class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = 0;
        it = vec2d.begin(), end = vec2d.end();
    }

    int next() {
        if(hasNext())
            return (*it)[i++];
    }

    bool hasNext() {
        while(it != end && (*it).size() == i){
            i = 0;
            it++;
        }
        return it != end;
    }
private: 
    vector<vector<int>>::iterator it, end;
    int i;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
