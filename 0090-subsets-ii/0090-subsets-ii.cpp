class Solution {
public:
    
    void generate(vector<int>& nums, int i, vector<int> &tmp, vector<vector<int>>&ans, bool isIgnored){
        if(i == nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        // Don't consider ith element
        generate(nums, i+1, tmp, ans, false);
        
        // If prev element was ignored, then ignore again
        if(i > 0 && nums[i] == nums[i-1] && !isIgnored)
            return;
        
        //Consider ith element
        tmp.push_back(nums[i]);
        generate(nums, i+1, tmp, ans, true);
        
        
        tmp.pop_back();
       

        
    }
    
//     // TC - O(2^N)   SC - O(2^N)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        sort(nums.begin(), nums.end());
        generate(nums, 0, tmp, ans, false);
        return ans;
    }
};