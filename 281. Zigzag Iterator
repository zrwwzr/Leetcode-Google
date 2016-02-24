class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = v1.begin(), end1 = v1.end();
        it2 = v2.begin(), end2 = v2.end();
        cnt = 0;
    }

    int next() {
        return (cnt++) % 2 == 0 ? (it1 != end1 ? *(it1++) : *(it2++)) : (it2 != end2 ? *(it2++) : *(it1++));
    }

    bool hasNext() {
        return !(it1 == end1 && it2 == end2);
    }
private:
    vector<int>::iterator it1, it2, end1, end2;
    int cnt;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
