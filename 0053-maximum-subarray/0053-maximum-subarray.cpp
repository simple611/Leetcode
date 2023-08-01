class Solution {
public:
    //TC - O(n)   SC- O(1)
    int maxSubArray(vector<int>& nums) {
//         int curMax = 0;
//         int maxSum = INT_MIN;
        
//         for(int i=0;i<nums.size();++i)
//         {
//             curMax += nums[i];
//             if(curMax > maxSum)
//                 maxSum = curMax;
            
//             if(curMax < 0)
//                 curMax = 0;
//         }
//         return maxSum;
        
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};