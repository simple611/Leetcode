class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int duplicate = -1;
        
        for(int i=0;i<nums.size();i++){
            int tmp = abs(nums[i]);
            if(nums[tmp]<0){
                duplicate = tmp;
                break;
            }
            nums[tmp]=nums[tmp]*-1;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = abs(nums[i]);
        }
        
        return duplicate;
        
//         int slow = nums[0];
//         int fast = nums[0];
        
//         do{
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }while(slow != fast);
        
//         slow = nums[0];
//         while(slow != fast){
//             slow = nums[slow];
//             fast = nums[fast];
//         }
//         return fast;
    }
};