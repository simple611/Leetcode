class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
//         // TC - O(n^3)  SC - O(1)
//         int count = 0, n = grid.size();
//         for(int r=0;r<n;r++){
//             for(int c=0;c<n;c++){
//                 bool match = true;
                
                
//                 for(int i=0;i<n;i++){
//                     if(grid[r][i] != grid[i][c]){
//                         match = false;
//                         break;
//                     }
//                 }
                
//                 count += match ?1 : 0;
//             }
//         }
//         return count;
        
        
        // Hash Map approach
        // TC - O(n^2) SC - O(n^2)
        
        int count = 0;
        int n = grid.size();
        
        map<vector<int>, int> mp;
        
        for(vector<int> row: grid){
            mp[row]++;
        }
        
        for(int j=0;j<grid[0].size();j++){
            
            vector<int> val;
            for(int k=0;k<n;k++){
                val.push_back(grid[k][j]);
            }
            count += mp[val];
        }
        return count;
    }
};