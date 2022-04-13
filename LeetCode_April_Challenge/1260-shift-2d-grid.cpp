class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> res(r, vector<int>(c,0));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int newIndex = (i*c+j +k)%(r*c);
                int row= newIndex/c;
                int col=newIndex%c;
                res[row][col] = grid[i][j];
                
                }
            }
        return res;
        }
};