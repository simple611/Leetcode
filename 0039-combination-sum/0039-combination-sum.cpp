class Solution {
public:
    
    void help(vector<int>& C, int t, int i, vector<int>&tmp, vector<vector<int>>& ans){
        
        if(t == 0){
            // found the list whose sum is equal to target
            ans.push_back(tmp);
            return;
        }
        
        if(i == C.size())
            return;
        
        if(t < 0)
            return;
        
        // skip ith ele
        help(C, t, i+1, tmp, ans);
        
        // pick ith ele
        tmp.push_back(C[i]);
        help(C, t-C[i], i, tmp, ans);
        
        //backtrack
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> tmp;
        
        help(candidates, target, 0, tmp, ans);
        
        return ans;
        
    }
};