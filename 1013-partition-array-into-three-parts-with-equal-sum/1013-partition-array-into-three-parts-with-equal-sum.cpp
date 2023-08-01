class Solution {
public:
    // TC - O(n)  SC- O(1)
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = 0;
        
        for(int a: arr){
            totalSum+=a;
        }
        
        if(totalSum %3 != 0)
            return false;
        int maxSum = totalSum/3;
        
//         bool part1= false, part2 = false, part3=false;
        
//         int preSum=0;
//         for(int a: arr){
//             preSum+=a;
            
//             if(!part1 && preSum == maxSum) part1=true;
//             else if(part1 && !part2 && preSum == maxSum*2) part2 = true;
//             else if(part1 && part2 && !part3 && preSum == maxSum*3) part3 = true;
//         }
        
//         if(part1 && part2 && part3){
//             return true;
//         }
        
//         return false;
        
        
        
        int curSum =0;
        int part=0;
        
        for(int a: arr){
            curSum+=a;
            
            if(curSum == maxSum){
                curSum=0;
                part++;
            }
        }
        
        return part >=3;
    }
};