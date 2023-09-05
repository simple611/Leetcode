class Solution {
public:
    // TC - O(log N)  SC - O(1)
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() -1;
        int ans = INT_MAX;
        
        while(low<=high){
            
            // If both left and right space is sorted
            if(nums[low] < nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }
            int mid = low+(high-low)/2;
            
            if(nums[low] <= nums[mid])  // left space is sorted
            {
                ans = min(ans, nums[low]);
                low = mid+1;
            } else { // right space is unsorted, means min can be in this space
                ans = min(ans, nums[mid]);
                high = mid-1; 
            }
            
        }
        return ans;
    }
};