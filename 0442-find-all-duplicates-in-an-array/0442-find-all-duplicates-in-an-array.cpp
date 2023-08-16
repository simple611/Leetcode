class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
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
};