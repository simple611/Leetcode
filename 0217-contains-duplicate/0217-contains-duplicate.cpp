#include <set>
class Solution {
public:
    
    // Brute force :: TC - O(n^2)    SC - O(1)
    // Sorting :: TC - O(nlogn)  SC - O(1)
    // Map/set :: TC - O(n)   SC- O(n)
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> m;
        
        for(int i=0;i<nums.size();i++){
            if(!(m.find(nums[i]) != m.end()))
                m.insert(nums[i]);
            else
                return true;
        }
        return false;
               
        
    }
               

};