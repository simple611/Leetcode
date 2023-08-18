class Solution {
public:
    
    // TC - O(E + V^2)  SC- O(E)
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        
        
        unordered_map<int, unordered_set<int>> adjMat;
        
        for(auto &road: roads){
            adjMat[road[0]].insert(road[1]);
            adjMat[road[1]].insert(road[0]);
        }
        
        for(int node1=0;node1<n;node1++){
            for(int node2 = node1+1;node2<n;node2++){
                int curRank = adjMat[node1].size() + adjMat[node2].size();
                if(adjMat[node1].find(node2)  != adjMat[node1].end()){
                    --curRank;   //Common edge present
                }
                
                maxRank = max(maxRank, curRank);
            }
        }
        
        return maxRank;
    }
};