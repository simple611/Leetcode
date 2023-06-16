class Solution {
public:
    vector<vector<long long>> table;
    long long mod = 1e9 + 7;
    
    
    
    int dfs(vector<int>& nums){
        int n = nums.size();
        if(n<=2) return 1;
        
        vector<int> left, right;
        
        for(int i=1;i<n;i++){
            if(nums[i]< nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        
        long long lAns = dfs(left) % mod;
        long long rAns = dfs(right) % mod;
        
        return (((table[n-1][left.size()] * lAns) % mod ) * rAns ) % mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n+1);
        
        for(int i=0;i<n+1;i++){
            table[i] = vector<long long>(n+1, 1);
            for(int j=1;j<i;j++){
                table[i][j] = (table[i-1][j] + table[i-1][j-1])%mod;
            }
        }
        
        long long ans = dfs(nums);
        return (ans-1)%mod;
        
    }
};