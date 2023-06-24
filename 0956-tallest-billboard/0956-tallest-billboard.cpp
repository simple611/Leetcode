class Solution_brute {
public:
    int ans;

    int dfs(vector<int>& rods, int pos, int s1, int s2){
        if(pos == rods.size()){
            if( s1 == s2)
                return s1;
            return 0;
        }

        int ans = 0;

        int opt1 = dfs(rods, pos+1, s1, s2);
        int opt2 = dfs(rods, pos+1, s1+rods[pos], s2);
        int opt3 = dfs(rods, pos+1, s1, s2+rods[pos]);

        return max({opt1, opt2, opt3});
    }
    int tallestBillboard(vector<int>& rods) {
        ans = 0;
        return dfs(rods, 0, 0, 0);
    }
};

/*
Reduce 1 of the state in above solution, as N * M * M would lead to MLE/TLE  where M = sum(Array)

Sore the difference of s1 and s2 in the state, so the difference would range from -M to M

Hence, number of states = N* ( 2 * M) , hence we reduced the time by M

*/

class Solution{
public:
    
    int dp[21][10001];   //21 - max length of rod, 10001 - sum(rods) * 2

    int dfs(vector<int>& rods, int pos, int diff){
        if(pos == rods.size()){
            if( diff == 0 )
                return 0;
            return INT_MIN;
        }

        if(dp[pos][diff + 5000] != -1)
            return dp[pos][diff + 5000];

        int opt1 = dfs(rods, pos+1, diff);
        int opt2 = dfs(rods, pos+1, diff+rods[pos]);
        int opt3 = rods[pos] + dfs(rods, pos+1, diff - rods[pos]);

        return dp[pos][diff + 5000] = max({opt1, opt2, opt3});
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp , -1 , sizeof(dp));
        int ans =  dfs(rods, 0, 0);
        
        return ans < 0 ? 0 : ans;

    }
};