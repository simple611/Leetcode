class Solution {
public:
    // TC - O(n^2)  SC - O(n)
    int lengthOfLIS_withoutBS(vector<int>& nums) {
        vector<int> lis(nums.size()+1, 1);
        int ans = 1;

        for(int i=1;i<nums.size();i++){
            int maxI = 0;
            // Find prev which are less than nums[i], and find value of lis which is max among them
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
    
    //TC - O(nlogn)  SC- O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            // Check if the elememt is not in the res array, then add it
            // else replace the element at lower bound with current element
            // Example: [2, 5, 3, 4, 7]
            // [2, 5]  => [2, 3]  , 5 replaced with 3 so that we can further have increasing subseq
            // [2, 5, 7] => [2, 3, 4, 7]
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};