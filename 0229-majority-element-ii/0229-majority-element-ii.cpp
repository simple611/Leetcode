class Solution {
public:
    
    // TC - O(n)  SC-O(n)
    vector<int> majorityElement_mapImplementation(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        vector<int> ans;
        
        int t = nums.size()/3;
        
        for(auto a: mp){
            if(a.second > t)
                ans.push_back(a.first);
        }
        return ans;
    }
    
    //TC - O(n)  SC-O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> output;
        int countMajority = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            if(num2 == element){
                count2++;
            }
        }
        if(count1 > countMajority){
            output.push_back(num1);
        }
        if(count2 > countMajority){
            output.push_back(num2);
        }
        return output;
    }
};