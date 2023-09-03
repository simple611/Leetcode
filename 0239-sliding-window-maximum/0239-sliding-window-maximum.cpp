class Solution {
public:
    // TC - O(n*k)  Sc - O(1)  TLE
    vector<int> maxSlidingWindow_bruteForce(vector<int>& nums, int k) {
        
        vector<int> ans;
        for(int i=0;i<=nums.size()-k;i++){
            int maxCur = INT_MIN;
            
            for(int j=i;j< i+k;j++){
                maxCur = max(maxCur, nums[j]);
            }
            
            ans.push_back(maxCur);
            
        }   
        return ans;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        priority_queue<pair<int, int>> pq;
        
        int start = 0, end =0;
        
        while(end< nums.size()) {
            
            pq.push({nums[end], end});
            
            if( end - start + 1 < k)  // keep incrementing end till it reaches size k
                end++;
            else if( end - start + 1 == k){
                
                // remove all the element which are not in the current window
                while(pq.top().second < start)
                    pq.pop();
                
                ans.push_back(pq.top().first);
                
                start++;
                end++;
                
            }
        }
        
        return ans;
    }
};