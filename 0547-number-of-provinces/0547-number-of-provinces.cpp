class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis){
        vis[node] = true;
        
        for(int i=0;i<isConnected.size(); i++){
            if(isConnected[node][i] && !vis[i])
                dfs(i, isConnected, vis);
        }
    }
    
    // TC - O(n^2)   SC - O(n)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans =0;
        
        vector<bool> vis(n, false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        
        return ans;
    }
};