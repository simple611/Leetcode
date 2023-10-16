class Solution {
public:
    vector<vector<int>> subsetSet;
    void generate(vector<int>& set, int i, vector<int>& nums){
        if(i == nums.size())
        {
            subsetSet.push_back(set);
            return;
        }
        
        // Consider ith element
        set.push_back(nums[i]);
        generate(set, i+1, nums);
        
        // Don't consider ith element
        set.pop_back();
        generate(set, i+1, nums);
        
    }
    
    // TC - O(N * 2^N)   SC - O(N * 2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        generate(set, 0, nums);
        return subsetSet;
    }
};