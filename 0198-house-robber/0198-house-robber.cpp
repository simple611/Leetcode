class Solution {
public:
    int maxRob(vector<int> & nums, int n)
    {
        if(n<0)
            return 0;
        return max(nums[n] + maxRob(nums, n-2), maxRob(nums, n-1));
    }
    int maxRob(vector<int> &nums, int n, int dp[])
    {
        if(n<0)
            return 0;
        if(dp[n] >=0)
            return dp[n];
        int res = max(nums[n]+maxRob(nums, n-2, dp), maxRob(nums, n-1, dp));
        dp[n] = res;
        return res;
    }
    
    int rob(vector<int>& nums) 
    {
        // Recursion TLE : TC --> 2^n
        // return maxRob(nums, nums.size()-1);
        
        // Recursion - Top down approach with memoization    
        // int n = nums.size();
        // int dp[n+1];
        // for(int i=0;i<=n;i++)
        //     dp[i]=-1;
        // return maxRob(nums, n-1, dp);
        
//         //Iterative - Bottom up approach
//         int n = nums.size();
//         if(n==0)
//             return 0;
//         if(n==1)
//             return nums[0];
//         int dp[n];
//         dp[0]=nums[0];
//         dp[1]= max(nums[0], nums[1]);
        
//         for(int i=2;i<n;i++)
//         {
//             dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
//         }
//         return dp[n-1];
        
            //Iterative - Bottom up approach Modified
            int n = nums.size();
            if(n==0)
                return 0;
            if(n==1)
                return nums[0];
            int prev_2 = nums[0];
            int prev_1 = max(nums[0], nums[1]);

            for(int i=2;i<n;i++)
            {
                int tmp = max(nums[i]+prev_2, prev_1);
                prev_2 = prev_1;
                prev_1 = tmp;
            }
            return max(prev_1, prev_2);
    }
};