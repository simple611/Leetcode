class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]]=true;
        int dis =0;
        
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                pair<int, int> t= q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int n_r = t.first + dir[k][0];
                    int n_c = t.second + dir[k][1];
                    
                    if(n_r >= 0 && n_r < rows && n_c >= 0 && n_c <cols && maze[n_r][n_c] == '.' && !vis[n_r][n_c]){
                        if(n_r == 0 || n_r == rows -1 || n_c == 0 || n_c == cols -1)
                            return dis+1;
                        
                        vis[n_r][n_c]=true;
                        q.push({n_r, n_c});
                    }
                }
                         
            }
            dis++;
        }
        return -1;
    }
};