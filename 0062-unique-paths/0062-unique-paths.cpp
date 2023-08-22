class Solution {
public:
    
    // TC - O(2^ m+n)   SC- O(m+n)
    int uniquePaths_brute(int m, int n , int i, int j){
        if(i>=m || j>=n) return 0;
        
        if(i == m-1 || j == n-1) return 1;
        
        return uniquePaths_brute(m, n, i+1, j) + uniquePaths_brute(m,n, i, j+1);
    }
    
    int dp[101][101]{};
    int uniquePaths_memoize(int m, int n, int i, int j){
        if(i>=m || j>=n) return 0;
        
        if(i == m-1 || j == n-1) return 1;
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = uniquePaths_memoize(m, n, i+1, j) + uniquePaths_memoize(m,n, i, j+1);
    }
    
    
    int uniquePaths(int m, int n) {
        // return uniquePaths_brute(m, n, 0, 0);  
        return uniquePaths_memoize(m, n, 0, 0); 
    }
    
    
    
    int uniquePaths_bottomUp(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};