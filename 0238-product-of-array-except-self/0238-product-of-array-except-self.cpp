class Solution {
public:
    
    // TC - O(n)  SC- O(1)
    vector<int> productExceptSelf_withDiv(vector<int>& nums) {
        
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
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n), ans(n);
        
        left[0] = nums[0];
        for(int i=1;i<n;i++){
            left[i] = nums[i] * left[i-1];
        }
        
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = nums[i] * right[i+1];
        }
        
        ans[0] = right[1];
        ans[n-1] = left[n-2];
        
        for(int i=1;i<n-1;i++){
            ans[i] = left[i-1]*right[i+1];    
        }
        
        return ans;
    }
};