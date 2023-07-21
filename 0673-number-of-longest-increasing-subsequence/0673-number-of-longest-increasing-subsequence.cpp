class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n+1, 1), count(n+1, 1);
        int maxLen =0, res =0;

        for(int i=0;i<nums.size();i++){
            int maxI = 0;
            for(int j=0;j<i;j++){        
                if(nums[i]>nums[j]){
                    if(lis[i] == lis[j]+1){
                        count[i] +=count[j];
                    } else if (lis[i] < lis[j]+1){
                        lis[i] = lis[j]+1;
                        count[i] = count[j];
                    }
                }
            }
            
            if(maxLen == lis[i])
                res +=count[i];
            if(lis[i] > maxLen){
                maxLen = lis[i];
                res = count[i];
            }
        }

        return res;

    }
};