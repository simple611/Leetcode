class Solution {
public:  
     // map<int,int> mp;
    // struct comp{
    //          bool operator()(int a, int b){
    //             if(mp[a]>mp[b])
    //                 return true;
    //             else return false;
    //         }
    //     };
    
    //TC - O(n log(n-k))  // Using hashmap approach
    vector<int> topKFrequent_hashMap(vector<int>& nums, int k) {
        if(k==nums.size()){
            return nums;
        }
        
        map<int,int> mp;
        for(int n: nums){
            mp[n]++;
        }

        auto comp = [&mp](int a, int b){return mp[a] > mp[b];};
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        
        for(auto p: mp){
            heap.push(p.first);
            if(heap.size() >k)
                heap.pop();
        }
        
        vector<int> res(k);
        
        // for(int i=0;i>k;i++){
        for(int i=k-1; i>=0;i--){
            // res.push_back(heap.top());
            res[i] = heap.top();
            heap.pop();
        }
        return res;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        for(int n: nums) mp[n]++;
        
        vector<vector<int>> buckets(nums.size()+1);
        for(auto item: mp){
            buckets[item.second].push_back(item.first);
        }
        
        vector<int> res;
        for(int i=nums.size(); i>=0;i--){
            if(res.size() == k)
                break;
            
            for(auto a: buckets[i]){
                res.push_back(a);
            }
        }
        
        return res;
        
    }
    
};