class Solution {
public:
    // TC: O(n)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        
        
        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            // if(mp.count(nums[i])){
            if(mp.find(n) != mp.end()) {
                if(abs(i-mp[n]) <=k)
                    return true;
            }
            mp[n] = i;
        }
        
        return false;
        
    }
};