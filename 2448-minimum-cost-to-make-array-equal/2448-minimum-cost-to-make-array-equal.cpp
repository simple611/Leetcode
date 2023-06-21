class Solution {
public:
    long long getSum(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
    
    long long minCost(vector<int>& A, vector<int>& cost) {
        
        // TC - O(nlogn)  SC - O(1)
        
        //This solution is based on the fact that the cost is the convex function (monotonically descending to, and then ascending from, a single minimum).

// For a given point, we compute the cost for it and its neighbor. By comparing those costs, we can tell whether the minimum is on the left or on the right.

// We binary-search for that minimum.
        long long l = 1, r = 1000000, res1 = 0, res2=0, x;
        while (l < r) {
            x = (l + r) / 2;
            res1 = getSum(A, cost, x);
            res2 = getSum(A, cost, x+1);
            
            if (res1 < res2)
                r = x;
            else
                l = x + 1;
        }
        return min(res1, res2);
    }


};