
class LRUCache_splice {
    int c;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache_splice(int capacity) {
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */