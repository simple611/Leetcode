class Solution {
public:
    
    
    // TC - O((k+m). log m)   SC- O(m) 
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        priority_queue<int, vector<int>, greater<int>> leftQ, rightQ;
        
        long long ans = 0;
        
        int cnt =0, i = 0, j = costs.size() -1;
        
        while(cnt < k){
            
            while(leftQ.size() < candidates && i<=j) leftQ.push(costs[i++]);
            
            while(rightQ.size() < candidates && j>= i) rightQ.push(costs[j--]);
            
            int a = leftQ.size() > 0 ? leftQ.top() : INT_MAX;
            int b  = rightQ.size() > 0 ? rightQ.top() : INT_MAX;
            
            if( a<=b){
                ans+=a;
                leftQ.pop();
            } else {
                ans+= b;
                rightQ.pop();
            }
            cnt++;
        }
        
        return ans;
    }
};