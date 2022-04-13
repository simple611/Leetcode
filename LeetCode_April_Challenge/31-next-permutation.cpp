class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//         int i=nums.size()-2;
        
//         for(;i>=0 && nums[i+1]<=nums[i];){
//             i--;
//         }
        
        int i= nums.size()-1;
        
        while(i>=0 && i-1 >=0 && nums[i-1] >= nums[i])
            i--;
        i =i-1;
        if(i>=0){
            int j= nums.size()-1;
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums,i,j);
        }
        reverse(nums, i+1);
    }
private:
    void reverse(vector<int>& nums, int start){
        int i=start,j=nums.size()-1;
        while(i<j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        
    }
};