class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*
        set<pair<int,int>> res;
        
        for(int i=0;i<nums.size();i++){
            res.insert({nums[i]*nums[i],i});
        }
        
        vector<int> ans;
        for(auto &p : res){
            ans.push_back(p.first);
        }
        return ans;
        */
        
        vector<int> ans(nums.size());
        int l=0,h=nums.size()-1;
        int k=nums.size()-1;
        while(l<=h){
            if(abs(nums[l]) >= abs(nums[h])){
                ans[k--]=nums[l]*nums[l];
                l++;
            }
            else{
                ans[k--]=nums[h]*nums[h];
                h--;
            }
        }
        return ans;
    }
};