class Solution {
public:
    // TC - O(n^2)  SC - O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size()+1, 1);
        int ans = 1;

        for(int i=1;i<nums.size();i++){
            int maxI = 0;
            for(int j=0;j<i;j++){        
                if(nums[i]>nums[j]){
                    maxI = max(maxI, lis[j]);
                }
            }
            lis[i] = 1+ maxI;
            ans = max(ans, lis[i]);
        }

        return ans;
    }
};