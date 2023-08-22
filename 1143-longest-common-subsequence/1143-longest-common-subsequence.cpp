class Solution {
public:
    
    // TC - O(2^ m+n)   SC- O(m+n)
    int LCS_recursive(string text1, string text2, int m, int n){
        if(m == 0 || n==0)
            return 0;
        
        if( text1[m-1] == text2[n-1]){
            return 1+ LCS_recursive(text1, text2, m-1, n-1);
        } else {
            return max(LCS_recursive(text1, text2, m-1, n), LCS_recursive(text1, text2, m, n-1));
        }
        
    }
    
    int dp[1001][1001];
    // TC - O(m*n)   Sc- O(m*n)
    int LCS_memoize(string &text1, string &text2, int m, int n){
        if(m == 0 || n==0)
            return 0;
        
        if( dp[m][n] != -1)
            return dp[m][n];
        
        if( text1[m-1] == text2[n-1]){
            return dp[m][n] = 1+ LCS_memoize(text1, text2, m-1, n-1);
        } else {
            return dp[m][n] = max(LCS_memoize(text1, text2, m-1, n), LCS_memoize(text1, text2, m, n-1));
        }
    }
    
    int LCS_bottomUp(string &text1, string &text2, int m, int n){
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); 
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
          
                if(text1[i-1] == text2[j-1]){
                 
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
             
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        // return LCS_recursive(text1, text2, text1.size(), text2.size());
        
        // memset(dp, -1, sizeof(dp));
        // return LCS_memoize(text1, text2, text1.size(), text2.size());
        
        
        return LCS_bottomUp(text1, text2, text1.size(), text2.size());
    }
};