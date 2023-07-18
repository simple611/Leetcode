class LRUCache {
private:
    int size = 0;
    unordered_map<int, pair<list<int>::iterator, int>> mp;   // map<key, pair<key iterator in list, value>>
    list<int> l_cache;
public:
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    void moveToFront(int key){
        l_cache.erase(mp[key].first);     //O(1)
        l_cache.push_front(key);       //O(1)
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */