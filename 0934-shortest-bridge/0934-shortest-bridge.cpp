class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis, queue<pair<int, int>> &q){
        if(r < 0 ||
           r >= grid.size() || c < 0 || c >= grid[0].size() || vis[r][c] || grid[r][c] == 0)
            return;
        vis[r][c]=true;
        // cout<<"DFS queue  push "<< r<< " "<< c<< endl; 
        q.push({r,c});
        
        for(int i=0;i<4;i++){
            int rn = r + dir[i][0];
            int cn = c + dir[i][1];
            dfs(grid, rn, cn, vis, q);
        }        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        
        
        int flag =0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(grid, i, j, vis, q);
                    flag = 1;
                    break;
                }        
            }
            if(flag == 1)
                break;
        }
        
       
        
        int dis = 0;
        while(!q.empty()){
            // cout<<"initial q size="<<q.size()<<endl;
            int size = q.size();
            for(int i=0;i<size;i++){
                pair<int, int> t = q.front();
                q.pop();
                
                for( int k=0;k<4;k++){
                    int n_R = t.first + dir[k][0];
                    int n_C = t.second + dir[k][1];
                    
                    if(n_R >= 0 && n_R < rows && n_C >= 0 && n_C < cols && !vis[n_R][n_C]){
                        if(grid[n_R][n_C] == 1){
                            // cout<<"Found"<<n_R<<","<<n_C<<endl;
                            return dis;
                        }
                        q.push({n_R, n_C});
                        // cout<<"BFS queue  push "<< n_R<< " "<< n_C<< endl;
                        vis[n_R][n_C] = true;
                        
                        
                    }
                }
                
            }
            dis++;
            // cout<<"q.size()="<<q.size()<<endl;
        }
        
        return -1;
    }
};