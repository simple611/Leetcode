class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
    
        long res=0;
        int mod = 1e9+7;
        for(int i=0;i<arr.size();i++){
            vector<int> count(101,0);
            for(int j=i+1;j<arr.size();j++){
                int k = target-arr[i]-arr[j];
                if(k>=0 && k<=100 && count[k]>0){
                    res+=count[k];
                    res%=mod;
                }
                count[arr[j]]++;
            }
        }
        return res;
    }
};