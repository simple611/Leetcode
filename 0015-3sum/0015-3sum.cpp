class Solution {
public:
    
    //TC - O(n^3 * logm) SC- O(m)  m-> no.of unique sets
    vector<vector<int>> threeSum_brute(vector<int>& nums) {
        
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
    
    
    //TC - O(n^2 * logm) SC- O(m)  m-> size of hashSet
    vector<vector<int>> threeSum_hashMap(vector<int>& nums) {
        
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            
            set<int> hashSet;
            for(int j = i+1;j<n;j++){
                int third = - (nums[i]+nums[j]);
                
                if(hashSet.find(third) != hashSet.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
    
    // TC - O(nlogn) + O(n^2)  SC - O(no. of unique sets) 
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum <0){
                    j++;
                } else if(sum > 0){
                    k--;
                } else {
                    // Found a set where sum = 0

                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
            
        }

        return res;
    }
    
};