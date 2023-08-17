class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        
        int maxDiff = INT_MIN;
        
        for(int i = 1; i<nums.size(); i++){
            int tmpDiff = nums[i]-nums[i-1];
            maxDiff = maxDiff<tmpDiff ? tmpDiff : maxDiff;
        }
        
        return maxDiff;
    }
};