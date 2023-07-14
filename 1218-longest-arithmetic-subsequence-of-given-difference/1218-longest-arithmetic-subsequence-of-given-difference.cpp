class Solution {
public:
    
    //TC - O(n)  SC- O(n)
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        
        int ans=1;
        
        for(auto& a: arr){
            int beforeA = dp[a-difference];
            dp[a] = 1 + beforeA;
            ans = max(ans, dp[a]);
        }
        
        return ans;
    }
};