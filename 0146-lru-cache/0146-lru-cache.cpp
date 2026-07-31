class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this -> key = key;
            this -> value = value;
            this -> prev = NULL;
            this -> next = NULL;
        }
    };
    unordered_map<int,Node*> cache;
    int cap;
    Node* head;
    Node* tail;
    void addToHead(Node* node) {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }
    void removeNode(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = NULL;
        node -> prev = NULL;
    }
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        moveToHead(node);
        return node -> value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
            Node* node = new Node(key, value);
            addToHead(node);
            cache[key] = node;
        }
        else {
            Node* node = cache[key];
            node -> value = value;
            moveToHead(node);
        }
        if(cache.size() > cap) {
            Node* lru = tail -> prev;
            removeNode(lru);
            cache.erase(lru -> key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */