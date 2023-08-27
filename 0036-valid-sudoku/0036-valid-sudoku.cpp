class Solution {
public:

    // TC - O()
    bool isValidSudoku_set(vector<vector<char>>& board) {
      
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxSet[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int boxIdx = (i/3)*3 + j/3;
                    if(rowSet[i].count(board[i][j]) || 
                       colSet[j].count(board[i][j]) || 
                       boxSet[boxIdx].count(board[i][j]))
                        return false;
                    rowSet[i].insert(board[i][j]);
                    colSet[j].insert(board[i][j]); 
                    boxSet[boxIdx].insert(board[i][j]);
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
      
        int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int boxIdx = (i/3)*3 + j/3;
                    if(row[i][num] || col[j][num] || box[boxIdx][num])
                        return false;
                       
                    row[i][num] =1;
                    col[j][num] = 1; 
                    box[boxIdx][num] =1;
                }
            }
        }
        return true;
    }
};