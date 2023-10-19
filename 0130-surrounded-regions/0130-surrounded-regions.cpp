class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols){
        if( i<0 || j<0 || i>=rows || j >= cols)
            return;
        if(grid[i][j] != 'O')
            return;
        grid[i][j] = '#';
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols);
        dfs(grid, i, j+1, rows, cols);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        
        if(m == 0) return;  
        
        int n = board[0].size();
     
     //Moving over firts and last column   
     for(int i=0; i<m; i++) {
         if(board[i][0] == 'O')
             dfs(board, i, 0, m, n);
         
         if(board[i][n-1] == 'O')
             dfs(board, i, n-1, m, n);
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<n; j++) {
         if(board[0][j] == 'O')
             dfs(board, 0, j, m, n);
         if(board[m-1][j] == 'O')
             dfs(board, m-1, j, m, n);
     }
        
     for(int i=0; i<m; i++)
         for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
    }
        
};