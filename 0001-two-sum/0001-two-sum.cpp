class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*// O(n^2) | O(1) space
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
                // else if(nums[i]+ nums[j] > target)
                //     break;
            }
        }
        return res;
        
        */
        
        // O(nlogn) | O(1) space
        
        
//         vector<pair<int,int>> v(nums.size());
//         for(int i=0;i<nums.size();i++){
//             v[i].first=nums[i];
//             v[i].second=i;
//         }
//         int n=nums.size(),i=0,j=n-1;
//         sort(v.begin(),v.end());
       
//         // vector<int> ans;
//         while(i<j){
//             if(v[i].first+v[j].first==target){
//                 return {v[i].second,v[j].second};
//             }
//             else if(v[i].first+v[j].first>target)j--;
//             else i++;
//         }
//         return {};
        
        //O(n) | O(n)
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            
            if(mp.find(val) != mp.end()){
                return {i, mp[val]};
            }
            mp[nums[i]] = i;
        }
        
        return {};
    }
};