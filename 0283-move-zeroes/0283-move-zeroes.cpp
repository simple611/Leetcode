class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*int in=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!= 0)
            {
                nums[in++]=nums[i];
            }
            
        }
        for(int i=in;i<nums.size();i++)
            nums[i]=0;
        */
        
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                swap(nums[l++],nums[i]);
        }
        
        
    }
};