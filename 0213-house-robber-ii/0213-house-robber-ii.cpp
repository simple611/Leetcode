class Solution {
public:
//     int maxRob(vector<int>& nums, int i, int start)
//     {
//         cout<<"i="<<i<<endl;
//         cout<<"start="<<start<<endl;
//         if(i<0 || i<start)
//             return 0;
//         if(i==0)
//             return nums[0];
//         if(i==1)
//             return max(nums[0], nums[1]);
//         if((i+1 % nums.size()) == start || i==start)
//         {
//             cout<<"int this"<<endl;
//             return maxRob(nums, i-1, start);
//         }
//         else
//         {
//              cout<<"int2 this"<<endl;
//             return max(nums[i] +maxRob(nums, i-2, start), maxRob(nums, i-1, start));
//         }
//     }
    
   
//     int rob_dp(vector<int>& nums) {
//         int n = nums.size()-1;
//         if(n<0)
//             return 0;
//         if(n==0)
//             return nums[0];
//         if(n==1)
//             return max(nums[0], nums[1]);
//         int start = (nums[0]> nums[1])? 0 :1;
//         return maxRob(nums, n, start);
//     }
    
    
    int houseRobber1(vector<int>& nums) {
        // dynamic programming - decide each problem by its sub-problems:
        int dp[nums.size()+1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i=2; i<nums.size(); i++)
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return dp[nums.size()-1];
    }
    
    int houseRobber(vector<int>& nums) {
        int n = nums.size();
            if(n==0)
                return 0;
            if(n==1)
                return nums[0];
            int prev_2 = nums[0];
            int prev_1 = max(nums[0], nums[1]);

            for(int i=2;i<n;i++)
            {
                int tmp = max(nums[i]+prev_2, prev_1);
                prev_2 = prev_1;
                prev_1 = tmp;
            }
            return max(prev_1, prev_2);
    }
    
    // TC - O(N)  SC- O(N+N) -> houseRobber1,
               // SC - O(N) -> houseRobber
    int rob(vector<int>& nums) {
        // edge cases:
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // either use first house and can't use last or last and not first:
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        return max(houseRobber(v1), houseRobber(v2));
    }
};