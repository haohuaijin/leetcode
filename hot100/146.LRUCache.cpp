class LRUCache {
public:
    struct ListNode {
        int key;
        int val;
        ListNode* prev;
        ListNode* next; 
        ListNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
        ListNode(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> map; //key -> value ListNode
    int count;
    int capacity;
    
    void add_to_head(ListNode* node){
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    void remove_node(ListNode* node){
        node->next->prev = node->prev;
        node->prev->next = node->next; 
    }
    
    LRUCache(int capacity) {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        this->count = 0;
    }
    
    int get(int key) {
        if(map.count(key) == 0){
            return -1;
        }
        remove_node(map[key]);
        add_to_head(map[key]);
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key]->val = value;
            remove_node(map[key]);
            add_to_head(map[key]);
            return;
        } 
        if(count == capacity){
            map.erase(tail->prev->key);
            ListNode* del = tail->prev;
            remove_node(del);
            delete del;
            count -= 1;
        }
        ListNode* node = new ListNode(key, value);
        map[key] = node;
        add_to_head(node);
        count += 1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
