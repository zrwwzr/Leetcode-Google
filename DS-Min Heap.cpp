class MinHeap{
private:
    size_t sz, capacity;
    int *arr;
    int left(int i) { return (i << 1) + 1; };
    int right(int i) { return (i + 1)<< 1; };
    int parent(int i) { return (i - 1) >> 1; }
    void minHeapify(int i){
        int l = left(i), r = right(i);
        int min_idx = i;
        if(l < sz && arr[l] < arr[min_idx])
            min_idx = l;
        if(r < sz && arr[r] < arr[min_idx])
            min_idx = r;
        if(min_idx != i){
            swap(arr[min_idx], arr[i]);
            minHeapify(min_idx);
        }
    }
public:
    MinHeap(const size_t cap){
        capacity = cap;
        sz = 0;
        arr = new int[capacity];
    }
    void insert(int key){
        if(sz == capacity) return;
        sz++;
        int i = sz - 1;
        arr[i] = key;
        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    int extract(){
        if(sz == 0) return INT_MAX;
        int rtn = arr[0];
        if(--sz != 0){
            swap(arr[sz], arr[0]);
            minHeapify(0);
        }
        return rtn;
    }
    int get(){ return sz > 0 ? arr[0] : INT_MAX; }
    bool empty(){ return sz == 0; }
    size_t size() { return sz; }
};
