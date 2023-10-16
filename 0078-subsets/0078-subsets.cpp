class Solution {
public:
    vector<vector<int>> subsetSet;
    void generate(vector<int>& nums, int i, vector<int> &tmp){
        if(i == nums.size())
        {
            subsetSet.push_back(tmp);
            return;
        }
        
        //Consider ith element
        tmp.push_back(nums[i]);
        generate(nums, i+1, tmp);
        
        // Don't consider ith element
        tmp.pop_back();
        generate(nums, i+1, tmp);

        
    }
    
//     // TC - O(2^N)   SC - O(2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        generate(nums, 0, tmp);
        return subsetSet;
    }

};