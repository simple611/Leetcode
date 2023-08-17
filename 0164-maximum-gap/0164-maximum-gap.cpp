class Solution {
public:
    
    // TC- O(nlogn) + O(n)   SC- O(1)
    int maximumGap__sorting(vector<int>& nums) {
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
    
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int minN = INT_MAX, maxN=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            minN = min(nums[i], minN);
            maxN = max(nums[i], maxN);
        }
        
        double gap = ((maxN - minN)*1.0)/(nums.size() -1);
        if(gap < 1.0 ) gap =1;
        
        vector<int> minBucket(nums.size(), INT_MAX);
        vector<int> maxBucket(nums.size(), INT_MIN);
        
        for(int i=0;i<nums.size();i++){
            int pos = (nums[i] - minN )/gap;
            
            minBucket[pos] = min(minBucket[pos], nums[i]);
            maxBucket[pos] = max(maxBucket[pos], nums[i]);
        }
        
        int prevMax = maxBucket[0];
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            if(minBucket[i] == INT_MAX) continue;
            ans = max(ans, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }
        return ans;
    }
};