class Solution {
public:
    // TC - O(nlogn)  SC- O(1)
    int firstMissingPositive_sorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // int maxElement = INT_MIN;
        // for(int a: nums){
        //     maxElement = max(maxElement, a);
        // }
        // int j=0;
        int count = 1;
        for(int i=0;i<= nums.size();){
            if(count == nums[i]){
                count++;
                i++;
                continue;
            }
            else if(count > nums[i]){
                i++;
            } else {
                break;
            }
        }
        
        return count;
    }
    
    // TC - O(n)  SC- O(1)
    int firstMissingPositive_withoutSwap(vector<int>& nums) {
        int n = nums.size();
        
        // Set all negative and greater than n numbers to n+1, since don't need to consider them
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i] > n)
                nums[i] = n+1;
        }
        
        // Mark all elements positive as negative if they exists
        for(int i=0;i<n;i++){
            if(abs(nums[i]) >=n+1) continue;
            int pos = abs(nums[i]);
            nums[pos-1] = -1 * abs(nums[pos-1]);
        }
        
        // Check for positive number and return its indx
        for(int i =0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        
        return n+1;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int ele=nums[i];
            
            if(ele>=1 && ele<=n){
                int pos=ele-1;
                
                if(nums[pos]!=ele){
                    swap(nums[pos],nums[i]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};