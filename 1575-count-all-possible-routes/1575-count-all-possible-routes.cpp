class Solution {
public:
    int solve(vector<int>& loc, int curCity, int finish, int remainingFuel,
              vector<vector<int>>& memo) {
        if (remainingFuel < 0) {
            return 0;
        }
        if (memo[curCity][remainingFuel] != -1) {
            return memo[curCity][remainingFuel];
        }

        int ans = curCity == finish ? 1 : 0;
        for (int nextCity = 0; nextCity < loc.size(); nextCity++) {
            if (nextCity != curCity) {
                ans = (ans + solve(loc, nextCity, finish,
                                   remainingFuel - abs(loc[curCity] - loc[nextCity]),
                                   memo)) % 1000000007;
            }
        }

        return memo[curCity][remainingFuel] = ans;
    }

    
    // TC - O(n^2 * fuel)  SC- O(n*fuel)
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        int n = locations.size();
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));

        return solve(locations, start, finish, fuel, memo);
    }
};