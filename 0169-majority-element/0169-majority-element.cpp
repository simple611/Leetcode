class Solution {
public:
    
    //TC - O(n)  SC- O(1)
    int majorityElement(vector<int>& nums) {
        //Boyer Moore Majority Voting
        int candidate = -1, vote = 0;
        for(int i=0;i<nums.size();i++){
            if(vote == 0){
                candidate = nums[i];
                vote = 1;
            } else if ( candidate == nums[i])
                vote++;
            else
                vote--;
        }
        return candidate;
    }
};