class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        sz = 0;
        //two sentiniel nodes
        front = new Node(0, 0);
        rear = new Node(0, 0);
        front->next = rear;
        rear->prev = front;
    }
    ~LRUCache(){
        delete front;
        delete rear;
        front = NULL;
        rear = NULL;
    }
    int get(int key) {
        int rtn = -1;
        if(map.count(key) != 0){
            rtn = map[key]->val;
            dequeue(map[key]);
            enqueue(new Node(key, rtn));
        }
        return rtn;
    }
    
    void set(int key, int value) {
        //if key is already in the cache
        if(map.count(key) == 0){
             //cache is full
            if(sz == capacity) dequeue(rear->prev);
            //attach new node to the front
            Node *node = new Node(key, value);
            enqueue(node);
        }
        else{
            Node *cur = map[key];
            dequeue(cur);
            enqueue(new Node(key, value));
        }
    }
private:
    struct Node{
        Node* prev, *next;
        int key, val;
        Node(int k, int v) : prev(NULL), next(NULL), key(k), val(v){}
    };
    Node *front, *rear;
    size_t sz, capacity;
    unordered_map<int, Node*> map;
    
    void enqueue(Node *node){
        node->next = front->next;
        front->next = node;
        node->next->prev = node;
        node->prev = front;
        //update size and map
        map[node->key] = node;
        sz++;
    }
    void dequeue(Node* deleted){
        deleted->prev->next = deleted->next;
        deleted->next->prev = deleted->prev;
        //update size and map
        map.erase(deleted->key);
        sz--;
        //delete node
        delete deleted;
        deleted = NULL;
    }
};
