class Solution {
public:
    int maxTime = INT_MIN;
    
    void dfs(vector<int> adjList[], vector<int>& informTime, int cur, int time){
        maxTime = max(maxTime, time);
        
        for(int adjNode: adjList[cur]){
            dfs(adjList, informTime, adjNode, time+ informTime[cur]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adjList[n];
        
        for(int i=0;i<n;i++){
            if(manager[i] != -1)
                adjList[manager[i]].push_back(i);
        }
        
        // // dfs approach
        // dfs(adjList, informTime, headID, 0);
        // return maxTime;
        
        //bfs approach
        
        queue<pair<int, int>> q;
        q.push({headID, 0});
        
        while(!q.empty()){
            auto manager = q.front();
            q.pop();
            
            int parent = manager.first;
            int time = manager.second;
            maxTime = max(maxTime, time);
            
            for(int adj : adjList[parent]){
                q.push({adj, time + informTime[parent]});
            }
            
        }
        return maxTime;
    }
};