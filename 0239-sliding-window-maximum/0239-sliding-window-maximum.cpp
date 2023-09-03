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
    
    // Tc - O(n log k ) ,k is the size of priority queue, SC - O(k)
    vector<int> maxSlidingWindow_priority_queue1(vector<int>& nums, int k) {
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
    
        // Tc - O(n log k ) ,k is the size of priority queue, SC - O(k)
    vector<int> maxSlidingWindow_priority_queue2(vector<int>& nums, int k) {
        // vector<int> ans(nums.size() -k +1);
        vector<int> ans;
        
        priority_queue<pair<int, int>> pq;
        
        for(int i=0;i<k;i++)
            pq.push({nums[i], i});
        
        // ans[0] = pq.top().first;
        ans.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++){
            pq.push({nums[i], i});
            
            //pop all elements not in window
            
            while(!pq.empty() && pq.top().second < i-k+1)
                pq.pop();
            
            // ans[i-k+1] = pq.top().first;
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
    
    //TC: O(n) + O(n)  Sc: O(k)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;
        
        for(int i=0;i<nums.size();i++){
            int curEle = nums[i];
            
            while(!dq.empty() && nums[dq.back()] < curEle)
                dq.pop_back();
            
            dq.push_back(i);
            
            while(!dq.empty() && dq.front() < i-k+1)
                dq.pop_front();
            
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    
    
    
};