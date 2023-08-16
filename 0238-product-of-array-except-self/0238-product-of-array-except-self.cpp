class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int product = 1; int zeroCnt = count(nums.begin(), nums.end(), 0);
        
        if(zeroCnt > 1) return vector<int>(nums.size(), 0);
        
        
        for(int a: nums){
            if(a) {
                product = product*a;
            }     
        }
        vector<int> res;
        for(int &a: nums){
            int tmp;
            if(zeroCnt) {
                tmp = a ? 0: product;
            } else{
                tmp = product/a;
            }
            
            res.push_back(tmp);
        }
        
        
        return res;
    }
};