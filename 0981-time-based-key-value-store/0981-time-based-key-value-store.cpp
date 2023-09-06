class TimeMap_MemoryExceeded {
public:

    
    // map of key value
    unordered_map<string, string> mp;
    
    //map of key -> timestamp
    unordered_map<string, vector<int>> tmp;
    
    
    int getTimeStamp(int time, vector<int>& arr){
        int l = 0, r = arr.size() - 1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] <= time){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
    TimeMap_MemoryExceeded() {
        mp.clear();    
    }
    
    void set(string key, string value, int timestamp) {
        string hash = key + "_" + to_string(timestamp);
        
        mp[hash] = value;
        tmp[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        
        vector<int> timeStampArr = tmp[key];
        
        
        int timeStampFinal = getTimeStamp(timestamp, timeStampArr);
        
        if(timeStampFinal == -1)
            return "";
        
        string hash = key + "_" + to_string(timeStampArr[timeStampFinal]);
        
        return mp[hash];
            
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


// TC - set -> O(M * L)  M, no. of set calls  
//    - get -> O(N * L log M)  N, no. of get calls , L: avg Length of key & value string
class TimeMap {
public:
    
    map<string, vector<pair<int, string>>> mp;
    
    int getTimeStamp(int time, vector<int>& arr){
        int l = 0, r = arr.size() - 1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid] <= time){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
    
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        // mp[key][timestamp] = value;
        
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        // If key is not present in map
        if(mp.find(key) == mp.end())
            return "";
         
        // timestamp is less than timestamps present for the key
        if(timestamp < mp[key][0].first)
            return "";
        
        int l = 0;
        int r = mp[key].size() - 1;
        
        string ans;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(mp[key][mid].first == timestamp){
                ans = mp[key][mid].second;
                return ans;
            } else if (mp[key][mid].first < timestamp){
                ans = mp[key][mid].second;
                l = mid+1;
            }
            else
                r=mid-1;
                
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */