class Solution {
public:
    
    // TC - O(n)  SC- O(n)
    vector<int> findDuplicates_hashMap(vector<int>& nums) {
        map<int, int> hashMap;
        
        for(int a: nums){
            hashMap[a]++;
        }
        
        
        vector<int> ans;
        
        for(auto a: hashMap){
            if(a.second == 2){
                ans.push_back(a.first);
            }
        }
        
        return ans;
    }
    
    // TC - O(nlogn) + O(n)  SC - O(1)
    vector<int> findDuplicates_sort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]){
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
    
    // TC - O(n)  SC- O(1)
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i]) - 1] < 0){
                res.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        
        return res;
    }
};