class Solution {
public:
    
    // TC - O(log N)  Sc - O(1)
    bool search(vector<int>& nums, int target) {
        /*int n = nums.size();
        int l=0,h=n-1,m;
        
        while(l<=h){
            m = l+(h-l)/2;
            
            if(nums[m]==target)
                return true;
            else if(nums[m] > nums[l]){
                if(target >= nums[l] && target < nums[m])
                    h=m-1;
                else
                    l=m+1;
            }
            else if(nums[m]<nums[l]){
                if(target > nums[m] && target <= nums[h])
                    l=m+1;
                else
                    h=m-1;
                
            }
            else{
                //normal binary search no rotation case
                // if(target < nums[m])
                //     h=m-1;
                // else
                //     l=m+1;
                l=l+1;
            }
        }
        return false;*/
        
        /*int n=nums.size();
        if(n==0) return false;
        
        int l=0, h=n-1;
        int m;
        
        while(l<=h){
            m=l+(h-l)/2;
            
            if(nums[m] == target)
                return true;
            
            //check if binary search is helpful
            if(nums[l] == nums[m]){
                l++;
                continue;
            }
            
            //check if mid exist in first array
            bool midArray = nums[l] <= nums[m];
            
            //check if target exist in first array
            bool targetArray = nums[l] <= target;
            
            //if both mid and target is in same sorted array
            if(!(midArray ^ targetArray)){
                if(nums[m] < target)
                    l=m+1;
                else
                    h=m-1;
            }else{
                if(midArray)  //mid in first and target in second
                    l=m+1;
                else   // mid in second and target in first
                    h=m-1;
            }
        }
        return false;
        */
        
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            while(low<high && nums[low]==nums[low+1])
                low++;
            while(low<high && nums[high]==nums[high-1])
                high--;
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[low]<=nums[mid])
            {                
                if(target<=nums[mid] && target>=nums[low])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else
            {
                if(target>=nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};