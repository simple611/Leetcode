class Solution {
public:
    
        
    void help(vector<int>& C, int t, int i, vector<int>&tmp, vector<vector<int>>& ans, bool isIgnored){
        
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
        help(C, t, i+1, tmp, ans, false);
        if(i> 0 && C[i] == C[i-1] && !isIgnored)
            return;
        
        // pick ith ele
        tmp.push_back(C[i]);
        help(C, t-C[i], i+1, tmp, ans, true);
        
        //backtrack
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        
        vector<int> tmp;
        
        sort(candidates.begin(), candidates.end());
        help(candidates, target, 0, tmp, ans, false);
        
        return ans;
        
    }
    
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
//     }
};