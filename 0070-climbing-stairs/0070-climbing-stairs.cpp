class Solution {
public:
    // TC = 2^n
    int climbStairs_Recursive_TLE(int n) {
        //Recursive approach ::TC = 2^n
        if(n == 0 || n==1)
            return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
        
    // Tc = O(n) ::SC = O(n)
    int climbStairs_bottomUp(int n) {
        // Bottom up approach with Memoization ::Tc = O(n) ::SC = O(n)
        int num[n+1];
        num[0]=1;
        num[1]=1;
        for(int i=2;i<=n;i++)
        {
            num[i]=num[i-1]+num[i-2];
        }
        return num[n];
    }   
    
    //Updated Bottom Up appraoch ::TC = O(n)  ::SC = 1
    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        int first = 1;
        int second = 1;
        int tmp = 0;
        for(int i=2;i<=n;i++)
        {
            tmp = first + second;
            first = second;
            second = tmp;
        }
        return second;
    }
};