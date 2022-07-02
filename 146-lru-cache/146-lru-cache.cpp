class LRUCache {
public:
    class Node{
        public:
        Node *next;
        Node *prev;
        int val;
        int key;
        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1, -1);
    int size;
    int top;
    unordered_map<int,Node *> dict;
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
        top=0;
    }
    
    int get(int key) {
        if(dict.find(key)==dict.end()) return -1;
        else{
            Node *t = dict[key];
            t->prev->next = t->next;
            t->next->prev = t->prev;
            t->next = head->next;
            head->next->prev = t;
            t->prev = head;
            head->next = t;
            return t->val;
        }
    }
    
    void put(int key, int value) {
        if(dict.find(key)==dict.end()){
            Node *temp = new Node(key,value);
            head->next->prev = temp;
            temp->next = head->next;
            temp->prev = head;
            head->next = temp;
            dict[key] = temp;
            if(top!=size) top++;
            else{
                Node *t = tail->prev;
                dict.erase(t->key);
                t->prev->next = tail;
                tail->prev = t->prev;
                delete(t);
            }
        }
        else{
            Node *t = dict[key];
            t->val = value;
            t->prev->next = t->next;
            t->next->prev = t->prev;
            t->next = head->next;
            head->next->prev = t;
            t->prev = head;
            head->next = t;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */