class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n= board[0].size();
        vector<vector<int>> popl(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0)
                    popl[i][j]+=board[i-1][j];
                if(i+1<m)
                    popl[i][j]+=board[i+1][j];
                if(j>0)
                    popl[i][j]+=board[i][j-1];
                if(j+1<n)
                    popl[i][j]+=board[i][j+1];
                if(i>0 && j>0)
                    popl[i][j]+=board[i-1][j-1];
                if(i+1<m && j+1<n)
                    popl[i][j]+=board[i+1][j+1];
                if(i+1<m && j>0)
                    popl[i][j]+=board[i+1][j-1];
                if(i>0 && j+1<n)
                    popl[i][j]+=board[i-1][j+1];

            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]){
                     if(popl[i][j] < 2)
                        board[i][j]=0;
                    else if(popl[i][j] > 3)
                        board[i][j]=0;
                }
                else{
                    if(popl[i][j] == 3)
                        board[i][j]=1;
                }
            }
        }
        
    }
};
