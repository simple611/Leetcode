class Solution {
public:
    // TC : O( row + col )  SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size(): 0;
        int row = 0, col = n-1;
        
        while(row< m && col >=0){
            if(matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};