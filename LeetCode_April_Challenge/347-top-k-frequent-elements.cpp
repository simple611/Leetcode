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
    vector<int> topKFrequent(vector<int>& nums, int k) {
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
};