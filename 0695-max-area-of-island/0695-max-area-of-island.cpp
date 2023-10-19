class Solution {
public:
    
    int area(int r, int c, vector<vector<bool>>& seen, vector<vector<int>>& grid ){
        if( r<0 || r>= grid.size() || c<0 || c>= grid[0].size() || seen[r][c] || grid[r][c] == 0)
            return 0;
        seen[r][c] = true;
        
        return (1+ area(r+1,c, seen, grid) + area(r-1, c, seen, grid) + area(r, c+1, seen, grid) + area(r, c-1, seen, grid));
    }
    
    
    // TC - O(m*n)  SC - O(m*n)
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        // Seen vector of m*n size
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
        
        int ans = 0;
        
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                ans = max(ans, area(r,c, seen, grid));
            }
        }
        return ans;
    }
};