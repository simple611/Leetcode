class Solution {
public:
    
    int solve(vector<vector<int>>& events, int n, int pos, int k, vector<vector<int>> &dp){
        
        if(pos>=n || k ==0)
            return 0;
        
        if(dp[pos][k] != -1)
            return dp[pos][k];
        
        //Linear Search for next index
        // int i;
        // for(i=pos+1;i<n;i++){
        //     if(events[i][0] > events[pos][1])
        //         break;
        // }
        
        // Binary search for next index
        vector<int> temp = {events[pos][1], INT_MAX, INT_MAX};
        int i=upper_bound(events.begin()+1,events.end(),temp)-events.begin();
        
        return dp[pos][k] = max(solve(events, n, pos+1, k, dp), events[pos][2] + solve(events, n, i, k-1, dp));
    }
    
    
    // TC - O((n*k)*n)  SC - O(n*k)  - Linear Search
    // TC - O((n*k)*log n)  SC - O(n*k)  - Binary Search
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(events, n, 0,k, dp);
    }
};