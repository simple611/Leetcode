class Solution {
public:
    // TC- O(n^2)  SC- O(1)
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int sR=0,sC=0;
        int eR=n-1,eC=n-1;
        int dir=0;
        int cnt=1;
        
        while(sR<=eR && sC<=eC){
            if(dir ==0){
                for(int i=sC;i<=eC;i++)
                    res[sR][i]=cnt++;
                sR++;
            }else if(dir ==1){
                for(int i=sR;i<=eR;i++)
                    res[i][eC]=cnt++;
                eC--;
            }else if(dir ==2){
                for(int i=eC;i>=sC;i--)
                    res[eR][i]=cnt++;
                eR--;
            }else if(dir ==3){
                for(int i=eR;i>=sR;i--)
                    res[i][sC]=cnt++;
                sC++;
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};