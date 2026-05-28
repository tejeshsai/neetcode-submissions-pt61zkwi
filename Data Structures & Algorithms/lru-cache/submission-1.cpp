class ListNode {
    public:
        ListNode* next;
        ListNode* prev;
        int val;
        int key;
        ListNode(int _key, int _val){
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {

public:
    ListNode* head;
    ListNode* tail;
    int count = 0;
    int capacity;
    unordered_map<int, ListNode*> hashmap;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void remove(ListNode* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insertAtTail(ListNode* node){
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }
    int get(int key) {
        if(hashmap.find(key)==hashmap.end()) return -1;
        else{
            ListNode* foundNode = hashmap[key];
            remove(foundNode);
            insertAtTail(foundNode);
            return foundNode->val;
        }

    }
    
    void put(int key, int value) {
       // Scenario 1 : If key doesnt exists, need to create a new key, in hashmap and new node at end of tail.
       if(hashmap.find(key)==hashmap.end()){
            ListNode* newNode = new ListNode(key, value);
            insertAtTail(newNode);
            count++;
            hashmap[key] = newNode;
            if(count>capacity){
                ListNode* headnext = head->next;
                remove(headnext);
                hashmap.erase(headnext->key);
                delete(headnext);
                count--;
            }
       }
       // Scenario 2 : Key exists, need to update value, and put that node at the end
       else{
            ListNode* nodeToEnd = hashmap[key];
            nodeToEnd->val = value;
            remove(nodeToEnd);
            insertAtTail(nodeToEnd);
       }
    
        
        
    }
};
