class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int n, int sum){
        if(sum == 0)
            return true;
        if(n==0)
            return false;
        if(sum< nums[n-1]){
            return isSubsetSum(nums, n-1, sum);
        } else {
            return isSubsetSum(nums, n-1, sum) || isSubsetSum(nums, n-1, sum- nums[n-1]);
        }
    }
    
    int dp[201][10001];
    bool isSubsetSumMem(vector<int>& nums, int n, int sum){
        if(sum == 0)
            return true;
        if(n==0)
            return false;
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        if(sum< nums[n-1]){
            return dp[n][sum] = isSubsetSum(nums, n-1, sum);
        } else {
            return dp[n][sum] = isSubsetSum(nums, n-1, sum) || isSubsetSum(nums, n-1, sum - nums[n-1]);
        }
    }
    
    bool canPartition(vector<int>& nums) {
//         int sum=0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//         }
        
//         if(sum%2 != 0)
//             return false;
//         else {
//             return isSubsetSum(nums, n, sum/2);
//         }
        
        // Recursion with memoization
//         int sum=0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//         }
//         // int dp[n+1][sum+1];
//         memset(dp, -1, sizeof(dp));
        
//         if(sum%2 != 0)
//             return false;
//         else {
//             return isSubsetSumMem(nums, n-1, sum/2);
//         }
        
        //Top Down DP
        // TC : O(M *N) + O(N)
        // SC : O(M *N)
        
        int sum =0;
        int n = nums.size();
        for(int i : nums){
            sum+=i;
        }
        
        if(sum%2 != 0)
            return false;
        
        int s = sum/2;
        bool dp[n+1][s+1];
        
        for(int i=0;i<n+1;i++){
            dp[i][0] = true;
        }
        for(int i=0;i<s+1;i++){
            dp[0][i] = false;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s+1;j++){
                if(j < nums[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][s];
    }
};