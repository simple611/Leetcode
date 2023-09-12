
class LRUCache_map{
    int c;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache_map(int capacity) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        c = capacity;
    }
    
    int get(int key) {
        if((m.find(key) == m.end())) return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            m[key]->second = value;
            return;
        }
        if(m.size() == c) {
            int del_key = l.back().first;
            l.pop_back();
            m.erase(del_key);
        }
        l.emplace_front(key, value);
        m[key] = l.begin();
    }
};
class LRUCache_other {
private:
    int size = 0;
    unordered_map<int, pair<list<int>::iterator, int>> mp;   // map<key, pair<key iterator in list, value>>
    list<int> l_cache;
public:
    
    LRUCache_other(int capacity) {
        size = capacity;
    }
    
    void moveToFront(int key){
        // l_cache.erase(mp[key].first);     //O(1)
        // l_cache.push_front(key);       //O(1)
        // mp[key].first = l_cache.begin();
        
        l_cache.splice(l_cache.begin(), l_cache, mp[key].first);
        mp[key].first = l_cache.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else{
            moveToFront(key);
            return mp[key].second;    //second value of pair is value
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            moveToFront(key);
        } else {
            l_cache.push_front(key);
            mp[key] = {l_cache.begin(), value};
            size--;
        }
        
        if(size < 0 ){
            // delete less recently used element
            mp.erase(l_cache.back());
            l_cache.pop_back();
            size++;
        }
    }
};



 class Node{
 public:
     int key;
     int val;
     Node* next;
     Node* prev;
     
     Node(int k, int v){
         key = k;
         val = v;
         prev = NULL;
         next = NULL;
     }
     
     
 };
    // Hash map + doubly linked list, left = LRU, right = MRU
    // get: update to MRU, put: update to MRU, remove LRU if full
class LRUCache{
private:
    int c;
    unordered_map<int, Node*> cache;
    Node *head;
    Node *tail;
    
    // TC- O(1)
    void remove(Node* delNode){
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
    }
    
    // insert node at head, i.e next to head;
    // TC - O(1)
    void insert(Node *newNode){
        // Node *prevHead = head;
        
        // cout<<"Insert val="<<newNode->val<<endl;
        Node *nextNode = head->next;
        Node *prevNode = head->prev;
        
        newNode->prev = head;
        newNode->next = nextNode;
        
        head->next = newNode;
        nextNode->prev = newNode;
        
        
    }

public:
    LRUCache(int capacity) {
        c = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        
        head->next = tail;
        tail->prev = head;
        
    }
    
    // TC - O(1), worst case O(N), beacuse of mp.find()
    int get(int key) {
        if((cache.find(key) != cache.end())) {      
            remove(cache[key]);
            insert(cache[key]);
            // cache[key] = head->next;
            return cache[key]->val;
        }
        return -1;
    }
    
    // TC - O(1), worst case O(N), beacuse of mp.find(), and erase
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            
            delete cache[key];
        }
        
        Node *newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        
        if(cache.size() > c){
            Node *lru = tail->prev;
            remove(tail->prev);
            cache.erase(lru->key);
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */