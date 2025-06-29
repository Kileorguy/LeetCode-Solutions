class LRUCache {
public:

    struct Node{
        int key;
        int value;
        Node *prev, *next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = nullptr; next = nullptr;
        }

    };
    Node *head = nullptr, *tail=nullptr;
    unordered_map<int,Node*> um; 

    void pushHead(Node *newNode){ 
        if(!head){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        um[newNode->key] = newNode;
    }

    void unlink(Node *node){

        if(node == head){
            head = node->next;
        }
        else if(node == tail){
            tail = node->prev;
        }

        if(node->prev){
            node->prev->next = node->next;
        }
        if(node->next){
            node->next->prev = node->prev;
        }
        node->next = nullptr;
        node->prev = nullptr;

        pushHead(node);
    }

    void popTail(){
        if(head==tail){
            um.erase(tail->key);
            head = nullptr; 
            tail = nullptr;
        }else{
            Node *temp = tail->prev;
            um.erase(tail->key);
            tail->next = nullptr;
            tail->prev = nullptr;
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }

    }

    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(um.count(key) <= 0){
            return -1;
        }
        unlink(um[key]);
        return(um[key]->value);
        
    }
    
    void put(int key, int value) {
        if(um.count(key) > 0){
            um[key]->value = value;
            unlink(um[key]);
            return;
        }
        if(um.size() >= cap){
            // cout << head->value << " " + to_string(tail->value) << endl;
            popTail();
        }
        pushHead(new Node(key, value));
    }
};