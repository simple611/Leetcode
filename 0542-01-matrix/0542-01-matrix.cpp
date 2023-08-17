class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        if(rows == 0)
            return mat;
        vector<vector<int>> dis(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int rn = cur.first + dir[i][0];
                int cn = cur.second + dir[i][1];
                
                if(rn >= 0 && rn < rows && cn >=0 && cn < cols && dis[rn][cn] == -1){
                        dis[rn][cn] = dis[cur.first][cur.second]+1;
                        q.push({rn, cn});              
                }
            }
        }
        
        return dis;
    }
};