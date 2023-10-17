class Solution {
public:
    int mymin(int a, int b)
    {
        if(a<=b)
            return a;
        else
            return b;
    }
    int costClimbStairs(vector<int>& cost, int n)
    {
        // Basic Recursion -- TLE ::TC - 2^n
        if(n < 0)
            return 0;
        if(n==0 || n==1)
            return cost[n];
        return cost[n] + mymin(costClimbStairs(cost, n-1), costClimbStairs(cost, n-2));
    }
    
    int costClimbStairsDP(vector<int>& cost, int n, int dp[])
    {
        // Top Down Recursion approach with memoization
        // cout<<"n="<<n<<endl;
        if(n < 0)
            return 0;
        if(n==0 || n==1)
            return cost[n];
        
        // cout<<dp[n]<<endl;
        
        if(dp[n]!= 0)
            return dp[n];
         
        dp[n] = cost[n] + mymin(costClimbStairsDP(cost, n-1, dp), costClimbStairsDP(cost, n-2, dp));
        // cout<<dp[n]<<endl;
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        // // Basic Recursion -- TLE
        // int n = cost.size();
        // return mymin(costClimbStairs(cost, n-1), costClimbStairs(cost, n-2));
        
        // Top Down REcursion approach with memoization
        int n = cost.size();
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=0;
        return mymin(costClimbStairsDP(cost, n-1, dp), costClimbStairsDP(cost, n-2, dp));
        
        // Bottom up approach with memoization ::TC O(n) SC O(n)
        // int n = cost.size();    
        // int num[n+1];
        // num[0]=cost[0];
        // num[1]=cost[1];
        // for(int i=2;i<n;i++)
        // {
        //     num[i] = cost[i] + mymin(num[i-1], num[i-2]);
        // }
        // return mymin(num[n-1], num[n-2]);
        
        // Bottom up appraoch modified ::TC O(n) SC 1            
        // int first = cost[0];
        // int second = cost[1];
        // for(int i=2; i<cost.size() ; i++)
        // {
        //     int tmp = cost[i] + min(first, second);
        //     first = second;
        //     second = tmp;
        // }
        // return mymin(first, second);
        
        
    }
};